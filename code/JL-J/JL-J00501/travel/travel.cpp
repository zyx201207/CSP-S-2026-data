#include <bits/stdc++.h>

using namespace std;
string c1,s1,c2,s2;
long long a=0000,b=000;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }else{
        cout<<0;
        cout<<0;
        cout<<0;
        cout<<0;
        return 0;
    }
    if(s1!=s2){
        cout<<0;
        cout<<0;
        cout<<0;
    }else{
        cout<<111;
    }
    return 0;
}
