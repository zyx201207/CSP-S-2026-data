#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxx=-1;
long long fun1(long long c,long long b){
    long long sa[1000],sb[1000],ans=0;
    long long pos1=0,pos2=0;
    while(c>0){
        sa[++pos1]=c%2;
        c/=2;
    }
    while(b>0){
        sb[++pos2]=b%2;
        b/=2;
    }
    for(long long i=1;i<=min(pos1,pos2);i++)
        if(sa[i]&&sb[i]) ans+=pow(2,i-1);
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    long long spec=pow(2,30)-1;
    for(long long i=1;i<=n;i++)cin>>a[i];
    if(m==n){
        for(long long i=1;i<=n;i++) spec=fun1(spec,a[i]);
        cout<<spec;
        return 0;
    }
    if(m==1){
        spec=-1;
        for(long long i=1;i<=n;i++) spec=max(spec,a[i]);
        cout<<spec;
        return 0;
    }
    if(m==2){
        for(long long i=1;i<=n;i++)
            for(long long j=i+1;j<=n;j++)
                maxx=max(maxx,fun1(a[i],a[j]));
        cout<<maxx;
        return 0;
    }
    else{
        cout<<a[n-m+1];
        return 0;
    }
    return 0;
}
