#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<1;
        string p1="",p2="";
        for(int i=0;i<=1;i++)
        {
            p1 = p1+s1[0];
        }
        for(int i=0;i<=1;i++)
        {
            p2 = p2+s2[0];
        }
        if(p1==p2)
        {
            cout<<1;
            char w1=s1[2],w2=s2[2];
            if(w1=='A'&&w2=='B'||w1=='B'&&w2=='A'||w1=='B'&&w2=='C'||w1=='C'&&w2=='B'||w1=='A'&&w2=='C'||w1=='C'&&w2=='A'||w1=='D'&&w2=='F'||w1=='F'&&w2=='D')
            {
                cout<<1;
                if(w1=='A'&&w2=='B'||w1=='B'&&w2=='A'||w1=='B'&&w2=='C'||w1=='C'&&w2=='B'||w1=='D'&&w2=='F'||w1=='F'&&w2=='D')
                {
                    cout<<1;
                }
                else
                {
                    cout<<0;
                }
            }
            else
            {
                cout<<"00";
            }
        }
        else
        {
            cout<<"000";
        }
    }
    else
    {
        cout<<"0000";
    }
    return 0;
}
