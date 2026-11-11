#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,maxn=INT_MIN;
ll a[200005];
inline ll read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+(ch-48);
        ch=getchar();
    }
    return x*f;
}
ll ak(int x,int y){
    ll ans=a[x];
    ans&=a[y];
    return ans;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+n+1);
    if(m==n){
        ll ans=a[1];
        for(int i=2;i<=n;i++)ans&=a[i];
        cout<<ans;
        return 0;
    }
    ll sum;
    for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i]-a[j]==1)continue;
            sum=ak(i,j);
            maxn=max(sum,maxn);
        }

    }
    cout<<maxn;
    return 0;
}
