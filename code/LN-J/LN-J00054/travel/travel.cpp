#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    string sa="";
    string sb="";
    char w1;
    char w2;
    for(int i=0;i<3;i++)
    {
        if(i==0||i==1)
        {
            sa+=s1[i];
            sb+=s2[i];
        }
        else
        {
            w1=s1[i];
            w2=s2[i];
        }
    }
    if(c1==c2)cout<<1;
    else cout<<0;

    if(sa==sb&&c1==c2)cout<<1;
    else cout<<0;

    if(w1>='A'&&w1<='C'&&w2>='A'&&w2<='C'&&sa==sb&&c1==c2)cout<<1;
    else if(w1=='D'&&w2=='F'&&w1=='F'&&w2<='D'&&sa==sb&&c1==c2)cout<<1;
    else cout<<0;

    if((w1=='A'&&w2=='B'||w1=='B'&&w2=='A') && sa==sb&&c1==c2)cout<<1;
    else if((w1=='B'&&w2=='C'||w1=='C'&&w2=='B') && sa==sb&&c1==c2)cout<<1;
    else if((w1=='D'&&w2=='F'||w1=='F'&&w2=='D') && sa==sb&&c1==c2)cout<<1;
    else cout<<0;
    return 0;
}

