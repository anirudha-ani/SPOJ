#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;


int x[20005];
int tree[20005];
int MAX = 20005 ;
int output[20005];
void update(int index , int value)
{
    int position ;
   while(index < MAX)
   {
       tree[index] += value;

       position = index&(-index);
       index += position;
   }
}

int query(int range)
{
    int summation = 0 ,position;

    while(range>0)
    {
        summation += tree[range];

        position = range & (-range);

        range -= position;
    }
    return summation ;
}
int main()
{
    int i ;
    memset(tree , 0 , sizeof(tree));
    update (1 , 1);

//    for(i = 1 ; i < 20002 ;i++)
//    {
//        update(i ,i+1);
//        update(i +1, -(i+1));
//    }

    int input_no ;
     update (1 , 1);
     scanf("%d", &input_no);
     int  j;
     for( i = input_no -1 ,j = 2; i > 0 ; i-- , j++)
     {
         update(j , i);
     }



    for(i = 1 ; i <= input_no ; i++)
    {
        int Query = query(i);
        cout <<"QUERY ::" <<Query << endl;
        cout << "MOD:: "<<Query%input_no << endl ;
//        output[(Query%input_no)]  = i;
    }

//    for(i = 0 ; i < input_no-1 ; i++)
//    {
//
//        printf("%d ",output[i]);
//    }
//     printf("%d\n",output[i]);
    return 0;
}
