#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    int c1,c2;string s1,s2;
    cin>>c1>>s1>>c2>>s2;

    if (c1==c2) cout<<1;
    else    cout<<0;
    string num1,num2;char k1,k2;
    for (int i=0;i<s1.size();i++)
    {
        if (isdigit(s1[i]))
            num1+=s1[i];
        else
            k1=s1[i];
    }
    for (int i=0;i<s2.size();i++)
    {
        if (isdigit(s2[i]))
            num2+=s2[i];
        else
            k2=s2[i];
    }
    if (num1==num2) cout<<1;
    else    cout<<0;
    bool flag = false;
;    if (('A'<=k1&&'C'>=k1&&'A'<=k2&&'C'>=k2)||('D'<=k1&&'F'>=k1&&'D'<=k2&&'F'>=k2)){cout<<1;flag = true;}
    else    cout<<0;
    if (flag)
    {
        if (abs(k1-k2)==1)  cout<<1;
        else    cout<<0;
    }
    else cout<<0;
    return 0;
}


