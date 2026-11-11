#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=5e5+10;
const ll MAX=1e18;
ll read(){
    ll ret=0,sgn=0,ch=getchar_unlocked();
    while(ch>'9'||ch<'0')sgn |= ch=='-',ch=getchar();
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar_unlocked();
    return sgn ?-ret:ret;
}
ll n;
ll m,a[MAXN],l=MAX,r=-MAX,mid,cnt,ans,sum;
ll st[MAXN];
bool check(ll mid){
    sum=0;
    for(int i=1;i<=mid;i++)st[i]=a[i],sum+=a[i];
    for(int i=1,j=mid;j<=n;){
        if(a[j]*mid-sum<=m)return 1;
        j++;
        st[j]=a[j];
        sum=sum+a[j]-a[i];
        i++;
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    //ios::sync_with_stdio(false);
    n=read(),m=read();
    for(int i=1;i<=n;i++)a[i]=read()/*,l=min(l,a[i]),r=max(r,a[i])*/;
    sort(a+1,a+1+n);
    //for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    r=n,l=1;
    while(l<r){
        mid=(l+r)/2;
        //cout<<l<<" "<<r<<" "<<mid<<endl;
        if(check(mid)){
            ans=max(ans,mid);
            l=mid+1;
        }
        else r=mid;
    }
    cout<<ans;
    return 0;
}