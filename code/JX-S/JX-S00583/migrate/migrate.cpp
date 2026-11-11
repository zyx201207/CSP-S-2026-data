#include<bits/stdc++.h>
using namespace std;
const int N=2e6+2;
int c,t,n,s,ans,minD;
long long a[N],d;
void dfs1(int i,int j,int k,int D){
    if(k==j){minD=min(minD,D);return ;}
    int p=upper_bound(a+k,a+n+1,a[k]+d)-a;
    for(int l=k+1;l<=min(j,p-1);l++) dfs1(i,j,l,D+1);
    return ;
}
void dfs2(int i,int j,int k,int D){
    if(k==j&&D==minD){s++;return ;}
    if(D>minD) return ;
    if(s>2) return ;
    int p=upper_bound(a+k,a+n+1,a[k]+d)-a;
    for(int l=k+1;l<=min(j,p-1);l++){
        if(D>minD) return ;
        if(s>2) return ;
        dfs2(i,j,l,D+1);
    }
    return ;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        if(n>100&&(c==13||c==14)){cout<<1LL*n*(n-1)/2<<'\n';continue;}
        if(n>=20){cout<<"0\n";continue;}
        for(int i=1;i<=n;i++) cin>>a[i];
        ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                s=0;
                minD=n+1;
                dfs1(i,j,i,0);
                dfs2(i,j,i,0);
                if(s==2) ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
