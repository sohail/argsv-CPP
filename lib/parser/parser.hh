/*
    lib/parser/parser.hh
    Written by, Sohail Qayum Malik soni@sharingeconomy.pk
 */

#include "../csv/src/parser.hh"

#ifndef		CC_TOKENIZER_ARGSV_CPP_PARSER_HH
#define		CC_TOKENIZER_ARGSV_CPP_PARSER_HH

typedef struct arg
{
    int i; // argv start index
    int j; // argv end index    
    struct arg* previous; // link to list
    struct arg* next; // link to list
    cc_tokenizer::string_character_traits<char>::int_type ln; // line number 
    cc_tokenizer::string_character_traits<char>::int_type tn; // token number    
}ARG;

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
                                      *ptr = {0, 0, NULL, NULL, 0, 0};\
                                      p.reset(LINES);\
                                      p.reset(TOKENS);\
                                      while (p.go_to_next_line() != cc_tokenizer::string_character_traits<char>::eof())\
                                      {\
                                          while (p.go_to_next_token() != cc_tokenizer::string_character_traits<char>::eof())\
                                          {\
                                              if (p.get_current_token().compare(b) == 0)\
                                              {\
                                                  ptr->ln = p.get_current_line_number();\
                                                  ptr->tn = p.get_current_token_number();\
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
                                          p.reset(TOKENS);\
                                          while(p.go_to_next_token() != cc_tokenizer::string_character_traits<char>::eof())\
                                          {\
                                              for (int i = 1; i < n; i++)\
                                              {\
                                                  if (p.get_current_token().compare(a[i]) == 0)\
                                                  {\
                                                      ptr->i = i;\
                                                      ptr->next = (ARG*)alloc_obj.allocate(sizeof(ARG));\
                                                      *(ptr->next) = {0, 0, ptr, NULL, 0, 0};\
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
                                                            }\
                                                            else if (i < ptr->j)\
                                                            {\
                                                                ptr->j = i;\
                                                            }\
                                                        }\
                                                    }\
                                                }\
                                            }\
                                            if (!ptr->j)\
                                            {\
                                                ptr->j = n - 1;\
                                            }\
                                            ptr = ptr->next;\
                                        }\
                                    }\

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
                                    foo.ln = (ptr_inner->next)->ln;\
                                    foo.tn = (ptr_inner->next)->tn;\
                                    \
                                    \
                                    (ptr_inner->next)->i = ptr_inner->i;\
                                    (ptr_inner->next)->j = ptr_inner->j;\
                                    (ptr_inner->next)->ln = ptr_inner->ln;\
                                    (ptr_inner->next)->tn = ptr_inner->tn;\
                                    \
                                    \
                                    ptr_inner->i = foo.i;\
                                    ptr_inner->j = foo.j;\
                                    ptr_inner->ln = foo.ln;\
                                    ptr_inner->tn = foo.tn;\
                                }\
                                ptr_inner = ptr_inner->next;\
                            }\
                            ptr_outer = ptr_outer->next;\
                        }\
                    }\

#endif