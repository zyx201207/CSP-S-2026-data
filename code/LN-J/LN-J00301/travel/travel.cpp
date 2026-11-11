#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",std.in);
    freopen("travel.out","w",std.out);
    long long a,b,c,d;
    char p='a',q='b';
    long long e=b+p;
    long long f=d+q;
    cin>>a>>e>>c>>f;
    if(a==c)
        cout<<1;
    else
        cout<<0;
    if((d+q)-(b+p)==1||(b+p)-(d+q)==1)
        cout<<111;
    else
        cout<<000;
    return 0;
}
