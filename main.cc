/*
    main.cc
    Written by, Sohail Qayum Malik soni@sharingeconomy.pk
 */

#include <iostream>
/*
    To change the default parsing behaviour of the CSV parser
    //#define GRAMMAR_END_OF_TOKEN_MARKER     ","
    //#define GRAMMAR_END_OF_TOKEN_MARKER_SIZE    1
 */
#define COMMAND "d,-d,dir,--dir,(displays a list of files and subdirectories in a directory)\nh,-h,help,--help,?,/?,(displays help screen)\nv,-v,version,--version,(displays version number)"

#include "lib/parser/parser.hh"

int main(int argc, char* argv[])
{     
    ARG arg_d;
    ARG arg_v;
    ARG arg_h;
    ARG help_str;     
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

    HELP(parser, help_str, ALL)
 /*   
    ARG* ptr = &help_str;
    while (1)
    {
        parser.reset(LINES);
        parser.reset(TOKENS);
        std::cout<<"ptr->ln = "<<ptr->ln<<std::endl;
        std::cout<<"ptr->tn = "<<ptr->tn<<std::endl;

        parser.get_line_by_number(ptr->ln);
        std::cout<<parser.get_token_by_number(ptr->tn).c_str()<<std::endl;

        if (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        else
        {
            break;
        }
    }
*/    
                 
    return 0;
}