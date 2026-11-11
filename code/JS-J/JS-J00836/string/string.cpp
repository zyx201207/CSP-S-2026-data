#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN=2*1e5+5;
ll n,num;
ll a[MAXN];
char c[MAXN];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        num+=a[i];
    }


    char du=c[1];
    int f=1;
    for(int i=2;i<=n;i++)
    {
        if(c[i]!=du) f=0;
    }
    if(f==1) cout<<0;


    else{
        cout<<num/2;
    }
    return 0;
}
