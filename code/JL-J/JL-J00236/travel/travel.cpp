#include<bits/stdc++.h>
using namespace std;

int main()
{

    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    int c1,c2,a1=0,a2=0,a3=0,a4=0;
    string s1,s2,p1,p2;
    char x1,x2;

    cin>>c1>>s1>>c2>>s2;


    if(c1==c2)
    {
        a1=1;

        if(s1[0]=='0')p1 = s1[1];
        else p1 = s1[0]+s1[1];

        if(s2[0]=='0')p2=s2[1];
        else p2 = s2[0]+s2[1];

        if(p1==p2)
        {
            a2=1;
            x1 = s1[2];
            x2 = s2[2];
            if((x1=='A' && x2=='B')||(x1=='B' && x2=='C')||(x1=='B' && x2=='A')||(x1=='C' && x2=='B')||(x1=='D' && x2=='F')||(x1=='F' && x2=='D'))
            {
                a3=1;
                a4=1;
            }
            else if((x1=='A' && x2=='C')||(x1=='C' && x2=='A'))
            {
                a3=1;
            }

        }

    }

    cout<<a1<<a2<<a3<<a4;
    return 0;

}
