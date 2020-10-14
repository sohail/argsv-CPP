/*
    lib/parser/parser.hh
    Written by, Sohail Qayum Malik soni@sharingeconomy.pk
 */

#include "../csv/src/parser.hh"

#ifndef		CC_TOKENIZER_ARGSV_CPP_PARSER_HH
#define		CC_TOKENIZER_ARGSV_CPP_PARSER_HH

/* 
    Get ready for the code bloat or...
    Eventually the rest of the file below this comment should be built/made into a composite
 */

typedef struct arg
{
    cc_tokenizer::string_character_traits<char>::size_type i; // argv start index
    cc_tokenizer::string_character_traits<char>::size_type j; // argv end index  
    int argc; // as the name suggests, argument count for this one specific command alone
    struct arg* previous; // link to list
    struct arg* next; // link to list
    cc_tokenizer::string_character_traits<char>::int_type ln; // line number 
    cc_tokenizer::string_character_traits<char>::int_type tn; // token number    
} ARG;

#define TRAVERSE_ARGV(a, n)  {\
                                 for (int i = 1; i < n; i++)\
                                 {\
                                     std::cout<<a[i]<<" ";\
                                 }\
                                 std::cout<<std::endl;\
                             }\

#define FIND_ARG(a, n, p, b, r)   {\
                                      cc_tokenizer::allocator<char> alloc_obj;\
                                      bool found = false;\
                                      ARG* ptr = &r;\
                                      *ptr = {0, 0, 0, NULL, NULL, 0, 0};\
                                      p.reset(LINES);\
                                      p.reset(TOKENS);\
                                      while (p.go_to_next_line() != cc_tokenizer::string_character_traits<char>::eof())\
                                      {\
                                          /*std::cout<<p.get_current_line_number()<<" -> "<<p.get_current_line().c_str()<<std::endl;*/\
                                          while (p.go_to_next_token() != cc_tokenizer::string_character_traits<char>::eof())\
                                          {\
                                              if (p.get_current_token().compare(b) == 0)\
                                              {\
                                                  ptr->ln = p.get_current_line_number();\
                                                  /*ptr->tn = p.get_current_token_number();*/\
                                                  found = true;\
                                                  break;\
                                              }\
                                          }\
                                          if (found)\
                                          {\
                                              break;\
                                          }\
                                      }\
                                      if (!found)\
                                      {\
                                      }\
                                      else\
                                      {\
                                          found = false;\
                                          /*p.reset(TOKENS);*/\
                                          for (int i = 1; i < n; i++)\
                                          {\
                                               p.reset(TOKENS);\
                                               while (p.go_to_next_token() != cc_tokenizer::string_character_traits<char>::eof())\
                                               {\
                                                   if (p.get_current_token().compare(a[i]) == 0)\
                                                   {\
                                                       ptr->i = i;\
                                                       /*ptr->ln = p.get_current_line_number();*/\
                                                       ptr->tn = p.get_current_token_number();\
                                                       ptr->next = (ARG*)alloc_obj.allocate(sizeof(ARG));\
                                                       *(ptr->next) = {0, 0, 0, ptr, NULL, ptr->ln, 0};\
                                                       ptr = ptr->next;\
                                                   }\
                                               }\
                                          }\
                                      }\
                                  }\

#define FIND_ARG_BLOCK(a, n, p, r)  {\
                                        ARG* ptr = &r;\
                                        while (ptr->i)\
                                        {\
                                            p.reset(LINES);\
                                            p.reset(TOKENS);\
                                            while (p.go_to_next_line() != cc_tokenizer::string_character_traits<char>::eof())\
                                            {\
                                                while (p.go_to_next_token() != cc_tokenizer::string_character_traits<char>::eof())\
                                                {\
                                                    for (int i = ptr->i + 1; i < n; i++)\
                                                    {\
                                                        if (p.get_current_token().compare(a[i]) == 0)\
                                                        {\
                                                            if (!ptr->j)\
                                                            {\
                                                                ptr->j = i;\
                                                                ptr->argc = ptr->j - ptr->i - 1;\
                                                            }\
                                                            else if (i < ptr->j)\
                                                            {\
                                                                ptr->j = i;\
                                                                ptr->argc = ptr->j - ptr->i - 1;\
                                                            }\
                                                        }\
                                                    }\
                                                }\
                                            }\
                                            if (!ptr->j)\
                                            {\
                                                ptr->j = n - 1;\
                                                ptr->argc = ptr->j - ptr->i;\
                                            }\
                                            ptr = ptr->next;\
                                        }\
                                    }\

/* 
   p is for an instance of parser
   r is where the found values will be returned or stored... it has to be an instance of type ARG 
   t is for token, which can be any thing it can be all in any caps as well
 */
#define HELP_STR_START    "("
#define HELP_STR_END      ")"
#define ALL               "ALL"
#define HELP(p, r, t)     {\
                                ARG* ptr = &r;\
                                *ptr = {0, 0, 0, NULL, NULL, 0, 0};\
                                cc_tokenizer::String<char> str = cc_tokenizer::String<char>(t);\
                                cc_tokenizer::allocator<char> alloc_obj;\
                                str.toUpper();\
                                p.reset(LINES);\
                                p.reset(TOKENS);\
                                if (str.compare(ALL) == 0)\
                                {\
                                    while (p.go_to_next_line() != cc_tokenizer::string_character_traits<char>::eof())\
                                    {\
                                        while (p.go_to_next_token() != cc_tokenizer::string_character_traits<char>::eof())\
                                        {\
                                            if (p.get_current_token().find(HELP_STR_START) == 0)\
                                            {\
                                                cc_tokenizer::string_character_traits<char>::size_type pos = p.get_current_token().find(HELP_STR_END);\
                                                if (pos != cc_tokenizer::String<char>::npos && pos == (p.get_current_token().size() - cc_tokenizer::String<char>(HELP_STR_END).size()))\
                                                {\
                                                    if (ptr->ln && ptr->tn)\
                                                    {\
                                                        ptr->next = (ARG*)alloc_obj.allocate(sizeof(ARG));\
                                                        *(ptr->next) = {0, 0, 0, ptr, NULL, 0, 0};\
                                                        ptr = ptr->next;\
                                                    }\
                                                    ptr->i = cc_tokenizer::String<char>(HELP_STR_START).size();\
                                                    ptr->j = pos;\
                                                    ptr->ln = p.get_current_line_number();\
                                                    ptr->tn = p.get_current_token_number();\
                                                }\
                                            }\
                                        }\
                                    }\
                                }\
                                else\
                                {\
                                    /* code */\
                                    for (cc_tokenizer::string_character_traits<char>::int_type i = 1; i <= p.get_total_number_of_lines(); i++)\
                                    {\
                                        p.get_line_by_number(i);\
                                        for (cc_tokenizer::string_character_traits<char>::int_type j = 1; j <= p.get_total_number_of_tokens(); j++)\
                                        {\
                                            if (p.get_token_by_number(j).compare(t) == 0)\
                                            {\
                                                *ptr = {0, 0, 0, NULL, NULL, i, 0};\
                                                break;\
                                            }\
                                        }\
                                        if (ptr->ln)\
                                        {\
                                            std::cout<<"Found it..."<<std::endl;\
                                            break;\
                                        }\
                                    }\
                                }\
                          }\
                                        
/* Bubble sort */
#define SORT_ARG(r) {\
                        ARG* ptr_outer = &r;\
                        while (ptr_outer->next != NULL)\
                        {\
                            ARG* ptr_inner = &r;\
                            while (ptr_inner->next != NULL)\
                            {\
                                if (ptr_inner->i > (ptr_inner->next)->i)\
                                {\
                                    ARG foo;\
                                    foo.i = (ptr_inner->next)->i;\
                                    foo.j = (ptr_inner->next)->j;\
                                    foo.argc = (ptr_inner->next)->argc;\
                                    foo.ln = (ptr_inner->next)->ln;\
                                    foo.tn = (ptr_inner->next)->tn;\
                                    \
                                    \
                                    (ptr_inner->next)->i = ptr_inner->i;\
                                    (ptr_inner->next)->j = ptr_inner->j;\
                                    (ptr_inner->next)->argc = ptr_inner->argc;\
                                    (ptr_inner->next)->ln = ptr_inner->ln;\
                                    (ptr_inner->next)->tn = ptr_inner->tn;\
                                    \
                                    \
                                    ptr_inner->i = foo.i;\
                                    ptr_inner->j = foo.j;\
                                    ptr_inner->argc = foo.argc;\
                                    ptr_inner->ln = foo.ln;\
                                    ptr_inner->tn = foo.tn;\
                                }\
                                ptr_inner = ptr_inner->next;\
                            }\
                            ptr_outer = ptr_outer->next;\
                        }\
                    }\

#endif