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
       Haven't yet tested, do not use */
    /*SORT_ARG(arg_d)*/ 
    if (arg_d.i)
    {
        /* TODO 
           Haven't yet tested, do not use */    
        /*SORT_ARG(arg_d)*/
        ARG* ptr = &arg_d;
        FIND_ARG_BLOCK(argv, argc, parser, arg_d)
        /* TODO 
           Haven't yet tested, do not use */
        /*SORT_ARG(arg_d)*/
        while (ptr->next != NULL)
        {
            if (ptr->argc == (ptr->j - ptr->i))
            {
                std::cout<<"* "<<argv[ptr->i]<<" --> "<<argv[ptr->j]<<"(last command at CLI) [ln = "<<ptr->ln<<", tn = "<<ptr->tn<<"]"<<", argc = "<<ptr->argc<<", j - i = "<<ptr->j - ptr->i<<", arguments[";
            }
            else 
            {
                std::cout<<"* "<<argv[ptr->i]<<" --> "<<argv[ptr->j]<<" [ln = "<<ptr->ln<<", tn = "<<ptr->tn<<"]"<<", argc = "<<ptr->argc<<", j - i = "<<ptr->j - ptr->i<<", arguments[";
            }
            /*
                Both of them would work as well
                //for (int i = ptr->i + 1; i < ptr->argc + ptr->i + 1; i++)
                //for (int i = ptr->i + 1; i < ptr->j; i++)
             */
            for (int i = 0; i < ptr->argc; i++)
            {
                /*
                    //std::cout<<argv[i]<<", ";
                 */
                std::cout<<argv[ptr->i + i + 1]<<", ";
            }
            std::cout<<"]"<<std::endl;
            ptr = ptr->next;            
        }
    }

    FIND_ARG(argv, argc, parser, "v", arg_v)    
    /* TODO 
       Haven't yet tested, do not use */
    /*SORT_ARG(arg)*/
    if (arg_v.i)
    {
        ARG* ptr = &arg_v;
        FIND_ARG_BLOCK(argv, argc, parser, arg_v)
        /* TODO 
        /* Haven't yet tested, do not use */
        /*SORT_ARG(arg_v)*/
        while (ptr->next != NULL)
        {            
            if (ptr->argc == (ptr->j - ptr->i))
            {
                std::cout<<"* "<<argv[ptr->i]<<" --> "<<argv[ptr->j]<<"(last command at CLI) [ln = "<<ptr->ln<<", tn = "<<ptr->tn<<"]"<<", argc = "<<ptr->argc<<", j - i = "<<ptr->j - ptr->i<<", arguments[";
            }
            else 
            {
                std::cout<<"* "<<argv[ptr->i]<<" --> "<<argv[ptr->j]<<" [ln = "<<ptr->ln<<", tn = "<<ptr->tn<<"]"<<", argc = "<<ptr->argc<<", j - i = "<<ptr->j - ptr->i<<", arguments[";
            }
            /*
                Both of them would work as well
                //for (int i = ptr->i + 1; i < ptr->argc + ptr->i + 1; i++)
                //for (int i = ptr->i + 1; i < ptr->j; i++)
             */   
            for (int i = 0; i < ptr->argc; i++)
            {
                /*       
                    //std::cout<<argv[i]<<", ";
                 */                    
                std::cout<<argv[ptr->i + i + 1]<<", ";
            }            
            std::cout<<"]"<<std::endl;
            ptr = ptr->next;
        }
    }

    FIND_ARG(argv, argc, parser, "?", arg_h)    
    /* TODO 
       Haven't yet tested, do not use */
    /*SORT_ARG(arg_h)*/
    if (arg_h.i)
    {
        ARG* ptr = &arg_h;
        FIND_ARG_BLOCK(argv, argc, parser, arg_h)
        /* TODO 
           Haven't yet tested, do not use */
        /*SORT_ARG(arg_h)*/
        while (ptr->next != NULL)
        {
            if (ptr->argc == (ptr->j - ptr->i))
            {
                std::cout<<"* "<<argv[ptr->i]<<" --> "<<argv[ptr->j]<<"(last command at CLI) [ln = "<<ptr->ln<<", tn = "<<ptr->tn<<"]"<<", argc = "<<ptr->argc<<", j - i = "<<ptr->j - ptr->i<<", arguments[";
            }
            else 
            {
                std::cout<<"* "<<argv[ptr->i]<<" --> "<<argv[ptr->j]<<" [ln = "<<ptr->ln<<", tn = "<<ptr->tn<<"]"<<", argc = "<<ptr->argc<<", j - i = "<<ptr->j - ptr->i<<", arguments[";
            }
            /*
                Both of them would work as well
                //for (int i = ptr->i + 1; i < ptr->argc + ptr->i + 1; i++)
                //for (int i = ptr->i + 1; i < ptr->j; i++)
             */
            for (int i = 0; i < ptr->argc; i++)
            {
                /*
                    //std::cout<<argv[i]<<", ";
                 */
                std::cout<<argv[ptr->i + i + 1]<<", ";
            }   
            std::cout<<"]"<<std::endl;
            ptr = ptr->next;
        }
    }
                 
    return 0;
}