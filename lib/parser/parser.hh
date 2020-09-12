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

#define TRAVERSE_ARGV(a, n)  for (int i = 1; i < n; i++)\
                             {\
                                 std::cout<<a[i]<<std::endl;\
                             }\

#define FIND_ARG(a, n, p, b, r)   {\
                                    bool found = false;\
                                    r = {0, NULL, NULL, 0, 0};\
                                    p.reset(LINES);\
                                    p.reset(TOKENS);\
                                    while (p.go_to_next_line() != cc_tokenizer::string_character_traits<char>::eof())\
                                    {\
                                        while (p.go_to_next_token() != cc_tokenizer::string_character_traits<char>::eof())\
                                        {\
                                            if (p.get_current_token().compare(b) == 0)\
                                            {\
                                                r.ln = p.get_current_line_number();\
                                                r.tn = p.get_current_token_number();\
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
                                                    r.i = i;\
                                                    found = true;\
                                                    /*std::cout<<a[i]<<std::endl;*/\
                                                }\
                                            }\
                                        }\
                                    }\
                                }\

#endif