/*
    main.cc
    Written by, Sohail Qayum Malik soni@sharingeconomy.pk
 */

#include <iostream>
#include "lib/parser/parser.hh"

#define COMMAND "d,-d,dir,--dir,(displays a list of files and subdirectories in a directory)\nh,-h,help,--help,?,/?,(displays help screen)\nv,-v,version,--version,(displays version number)"

int main(int argc, char* argv[])
{     
    ARG arg_d;
    ARG arg_v;
    ARG arg_h;     
    cc_tokenizer::csv_parser<cc_tokenizer::String<char>, char> parser(cc_tokenizer::String<char>(COMMAND));
    
    /*TRAVERSE_ARGV(argv, argc)*/

    FIND_ARG(argv, argc, parser, "dir", arg_d)
    /* TODO 
    /* Does not work here */
    /* SORT_ARG(arg) */
    if (arg_d.i)
    {
        ARG* ptr = &arg_d;
        FIND_ARG_BLOCK(argv, argc, parser, arg_d)
        /*SORT_ARG(arg_d)*/
        while (ptr->next != NULL)
        {
            std::cout<<"* "<<argv[ptr->i]<<" --> "<<argv[ptr->j]<<std::endl;
            ptr = ptr->next;
        }
    }

    FIND_ARG(argv, argc, parser, "v", arg_v)
    /* TODO 
    /* Does not work here */
    /* SORT_ARG(arg) */
    if (arg_v.i)
    {
        ARG* ptr = &arg_v;
        FIND_ARG_BLOCK(argv, argc, parser, arg_v)
        /*SORT_ARG(arg_v)*/
        while (ptr->next != NULL)
        {
            std::cout<<"* "<<argv[ptr->i]<<" --> "<<argv[ptr->j]<<std::endl;
            ptr = ptr->next;
        }
    }

    FIND_ARG(argv, argc, parser, "?", arg_h)
    /* TODO 
    /* Does not work here */
    /* SORT_ARG(arg_h) */
    if (arg_h.i)
    {
        ARG* ptr = &arg_h;
        FIND_ARG_BLOCK(argv, argc, parser, arg_h)
        /*SORT_ARG(arg_h)*/
        while (ptr->next != NULL)
        {
            std::cout<<"* "<<argv[ptr->i]<<" --> "<<argv[ptr->j]<<std::endl;
            ptr = ptr->next;
        }
    }
                 
    return 0;
}