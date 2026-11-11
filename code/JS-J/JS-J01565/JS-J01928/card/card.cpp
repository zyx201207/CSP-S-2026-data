#include<bits/stdc++.h>
#include<set>
using namespace std;
using ll=long long;
ll n,m,a[500005],dif[500005];
ll ans[300005];
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return x*f;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    n=read(),m=read();
    for(ll i=1;i<=n;i++){
        a[i]=read();
        if(ans[a[i]]==0){
            ans[a[i]]=i;
            dif[i]=ans[a[i]]-ans[a[i]-1];
        }
        else dif[ans[a[i]]]+=(i-1),dif[ans[a[i]]+1]-=i,dif[i]+=i;
    }
    ll sum=0;
    for(ll i=1;i<=m;i++){
        sum+=dif[i];
        cout<<sum<<' ';
    }
}