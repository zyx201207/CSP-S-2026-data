#include<bits/stdc++.h>
using namespace std;
long long n,m;
const long long N=2e5+10;
long long a[N],ans;
long long b[N],e[N];
void dfs(long long now,long long choose ,long long andd){
    if(m==choose){
        ans=max(ans,andd);
        return;
    }
    if(now==n+1) return;
    if(now+m-choose-1>n) return;
    dfs(now+1,choose+1,andd&a[now]);
    dfs(now+1,choose,andd);
    return;
}
bool check(int x){
    while(x){
        if(x%2==0) return 0;
        x/=2;
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    long long tsa=1;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        if(check(a[i])==0) tsa=0;
    }
    if(tsa){
        long long maxx=0;
        for(long long i=1;i<=n;i++){
            maxx=max(maxx,a[i]);
        }
        cout<<maxx;
        return 0;
    }
    if(m==n-1){
            b[1]=a[1];e[n]=a[n];long long maxx=0;

        for(long long i=2;i<=n;i++){
            b[i]=b[i-1]&a[i];
        }
        for(long long i=n-1;i>=1;i--){
            e[i]=e[i+1]&a[i];
        }
        for(long long i=2;i<n;i++){
            maxx=max(maxx,b[i-1]&e[i+1]);
        }
        maxx=max(maxx,e[2]);
        maxx=max(maxx,b[n-1]);
        cout<<maxx;
        return 0;
    }
    dfs(1,0,(1<<32)-1);

    cout<<ans;
    return 0;
}
