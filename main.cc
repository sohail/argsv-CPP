/*
    main.cc
    Written by, Sohail Qayum Malik soni@sharingeconomy.pk
 */

#include <iostream>
#include "lib/parser/parser.hh"

#define COMMAND "d,-d,dir,--dir,(displays a list of files and subdirectories in a directory)\nh,-h,help,--help,?,/?,(displays help screen)\nv,-v,version,--version,(displays version number)"

int main(int argc, char* argv[])
{     
    ARG arg;     
    cc_tokenizer::csv_parser<cc_tokenizer::String<char>, char> parser(cc_tokenizer::String<char>(COMMAND));

    /*
    while (parser.go_to_next_line() != cc_tokenizer::string_character_traits<char>::eof())
    {
        std::cout<<parser.get_current_line().c_str()<<std::endl;
        while (parser.go_to_next_token() != cc_tokenizer::string_character_traits<char>::eof())
        {
            std::cout<<parser.get_current_token().c_str()<<std::endl;
        }
    }
     */

    //TRAVERSE_ARGV(argv, argc)
    FIND_ARG(argv, argc, parser, "d", arg)
     
    return 0;
}