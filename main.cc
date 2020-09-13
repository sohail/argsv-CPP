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
    
    TRAVERSE_ARGV(argv, argc)

    FIND_ARG(argv, argc, parser, "v", arg)
    if (arg.i)
    {
        ARG* ptr = &arg;
        FIND_ARG_BLOCK(argv, argc, parser, arg)
        while (ptr->next != NULL)
        {
            std::cout<<"--> "<<argv[ptr->i]<<std::endl;
            ptr = ptr->next;
        }
    }
                 
    return 0;
}