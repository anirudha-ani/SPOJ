//
//  main.cpp
//  TEST - Life, the Universe, and Everything
//
//  Created by Anirudha Paul on 4/21/15.
//  Copyright (c) 2015 Anirudha Paul. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{
    int input;
    
    cin >> input ;
    
    while (input != 42)
    {
        cout << input << endl ;
        cin >> input ;
    }
    
    return 0;
}
