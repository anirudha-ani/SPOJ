//
//  main.cpp
//  PRIME1 - Prime Generator
//
//  Created by Anirudha Paul on 4/21/15.
//  Copyright (c) 2015 Anirudha Paul. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <new>

using namespace std;

//এইটাতে double সিভ use করতে হয় । কারণ 1000000000 পর্যন্ত সিভ দিয়ে প্রাইম বের করলে TLE খাবে memory ৯৬০ MB র মত লাগে
//তাই কম টাইমের এবং মেমোরিতে করার জন্য root পর্যন্ত সিভ করে তারপর সেই টা দিয়ে given range এ আবার সিভ মেথড apply করলেই
//voila !!! :-D

int main(int argc, const char * argv[])
{
    bool *prime;
    
    prime =  new bool[31622];
    
    for (int i = 0 ; i <31622 ; i++)
    {
        prime[i] = true ;
    }
    
    
    for (int i = 2 ; i <= 31622; i++)
    {
        if (prime[i] == true)
        {
            for (int j = 2; j*i <31622 ; j++)
            {
                prime[j*i] = false;
            }
        }
    }
    
    int cases;
    
    scanf("%d", &cases);
    
    for ( int i = 0 ; i < cases ; i++)
    {
        int lowerLimit , limit ;
        scanf ( "%d %d" , &lowerLimit , &limit);
        
        
        
        for (int i =lowerLimit ; i <= limit ; i++)
        {
           if (i <= 31622 && i != 1 && prime [i] == true)
               {
                   cout << i << endl ;
               }
           else if (i > 31622 && i <= 1000000000)
               {
                   int flag = 1;
                   for (int x = 2 ; x <=31622 ; x++)
                   {
                       if (prime [x] == true && i%x == 0)
                       {
                           flag = 0;
                           break;
                       }
                   }
                   if (flag == 1)
                   {
                       cout << i << endl ;
                   }
               }
            
        }

    }
    delete [] prime;
    return 0;
}