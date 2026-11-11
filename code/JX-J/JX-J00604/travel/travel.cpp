#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen('travel.in','r',stdin)
    //freopen('travel.out','w',stdout)
    int q=0,w=0,e=0,r=0,c1;s1;c2;s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        q=1;
    }
    if(q==1 && s1[1]==s2[1] && s1[0]==s2[0])
    {
        w=1;
    }
    if (w==1)
    {
        if('A'<=s1[2]<='C' && 'A'<=s2[2]<='C')
        {
            e=1;
        }
        if('D'<=s1[2]<='F' && 'D'<=s2[2]<='F')
        {
            e=1;
        }
    }
    if(e==1)
    {
        if('A'<=s1[2]<='B' && 'A'<=s2[2]<='B')
        {
            r=1;
        }
        if('B'<=s1[2]<='C' && 'B'<=s2[2]<='C')
        {
            r=1;
        }
        if('D'<=s1[2]<='F' && 'D'<=s2[2]<='F')
        {
            r=1;
        }
    }
    cout<<q<<w<<e<<r;
      
    
    
    
    
                                           
    
    
    return 0;
}
