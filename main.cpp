#include <iostream>

const int MIN_LEGAL_ARGS = 4;


int main(int argc, char *argv[])
{
    if(argc < MIN_LEGAL_ARGS)
    {
        std::cerr << "Usage: find_the_author<frequent_words.txt> <text1> ...!" << std::endl;
        exit(-1);
    }
    //input frequent words

    //input uknown + score

    for(int i = 3; i <= argc; i++)
    {
        //calculate score
    }
    //print max
    std::cout << "Hello, World!" << std::endl;
    return 0;
}