#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
unsigned long long n,m,k,d;
long long a[N],s[N];
bool okb=1,okc=1;
bool check(long long mid,long long x){return (a[x]*(x-mid+1)+s[mid-1]-s[x])<=m;}
unsigned long long solve(long long x){
    int l=1,r=x;
    while(l<r){
        int mid=(l+r)>>1;
        if(check(mid,x)){
            r=mid;
        }else l=mid+1;
    }
    return x-l+1;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i!=1&&a[i]!=a[i-1])okc=0;
    }
    sort(a+1,a+n+1);
    d=a[2]-a[1];
    for(int i=3;i<=n;i++)
        if((a[i]-a[i-1])!=d)okb=0;
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    if(okc){
        cout<<n<<"\n";
        return 0;
    }
    if(okb){
        unsigned long long ans=(-1+sqrt(1+8*m/d))/2+1;
        cout<<min(n,ans)<<"\n";
        return 0;
    }
    unsigned long long ans=1;
    for(long long i=n;i>=ans;i--){
        ans=max(ans,solve(i));
    }
    cout<<ans<<"\n";
    return 0;
}
