#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 500005
ll read(){
    ll f=0,x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')
        f|=ch=='-',ch=getchar();
    while(ch>='0'&&ch<='9')
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return f?-x:x;
}
ll n,m,a[N],all,s[N];
bool check(int l,int r){
    return m>=a[r]*(r-l)-(s[r-1]-s[l-1]);
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    n=read(),m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    all=1;
    for(ll i=1,j=1;i<n;i++){
        while(j<n&&check(i,j+1))j++;
        all=max(all,j-i+1);
    }
    cout<<all;
    return 0;
}
