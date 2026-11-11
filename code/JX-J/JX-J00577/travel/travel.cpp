#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>c2;
    if(c1==c2)
    {
        cout<<1;
    }
    else{
        cout<<0;
    }
    for(int i=1;i<=s1.lengh();i++)
    {
        cin>>s1[i];
    }
    for(int i=1;i<=s2.lengh();i++)
    {
        cin>>s2[i];
    }
    for(int i=1;i<=3;i++)
    {
        if(s1[i]==s2[i]){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    return 0;
}
