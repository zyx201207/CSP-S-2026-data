#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005];
bool f[500005];
int cnt=-1,ans=-1;
void dfs(long long q,int dep,long long sum){
    if(sum>m){
        cnt=max(dep-1,cnt);
        return;
    }
    cnt=max(dep,cnt);
    for(int i=1;i<=n;i++){
        if(a[i]<=q&&f[i]==0){
            f[i]=1;
            dfs(q,dep+1,sum+q-a[i]);
            f[i]=0;
        }
    }

}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    long long r=0,l=INT_MAX;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        r=max(r,a[i]);
        l=min(l,a[i]);
    }
    l--;
    while(l+1<r){
        long long mid=(l+r)/2;
        cnt=-1;
        dfs(mid,0,0);
        if(cnt<=ans){
            r=mid;
        }else{
            ans=cnt;
            l=mid;
        }
    }
    printf("%lld",ans);
    return 0;
}
