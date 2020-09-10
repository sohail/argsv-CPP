/*
    lib/parser/parser.hh
    Written by, Sohail Qayum Malik soni@sharingeconomy.pk
 */
#include "../csv/src/parser.hh"

#define TRAVERSE_ARGV(a, n)  for (int i = 1; i < n; i++)\
                             {\
                                 std::cout<<a[i]<<std::endl;\
                             }\

#define FIND_ARG(a, n, p, b)    while (p.go_to_next_line() != cc_tokenizer::string_character_traits<char>::eof())\
                                {\
                                    while (p.go_to_next_token() != cc_tokenizer::string_character_traits<char>::eof())\
                                    {\
                                        if (p.get_current_token().compare(b) == 0)\
                                        {\
                                            std::cout<<p.get_current_line().c_str()<<std::endl;\
                                            break;\
                                        }\
                                    }\
                                }\

