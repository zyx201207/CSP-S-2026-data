#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
    ll res=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        res=10*res+ch-'0';
        ch=getchar();
    }
    return res*f;
}
const int N=5e5+5;
ll n,m,a[N],sum,ans=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    sort(a+1,a+n+1);
    sum=a[1];
    for(ll r=2,l=1;r<=n;r++){
        sum+=a[r];
        while(l<r&&a[r]*(r-l+1)-sum>m){
            sum-=a[l];
            l++;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
