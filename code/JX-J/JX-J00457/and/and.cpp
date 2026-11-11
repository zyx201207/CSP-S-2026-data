#include <bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
int n,m;
long long ans=-1;;
long long a[N];
bool visited[N];
void dfs(int x,int cnt,long long sum){
    if(cnt>=m) ans=max(ans,sum);
    for(int i=0;i<n;++i){
        if(!visited[i]){
            visited[i]=true;
            dfs(i,cnt+1,(sum&a[i]));
            visited[i]=false;
        }
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    long long maxn=-1;
    for(int i=0;i<n;++i){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    if(m==1){
        ans=maxn;
    }else if(m==n){
        ans=a[0];
        for(int i=0;i<n;++i){
            ans=(ans&a[i]);
        }
    }else{
        for(int i=0;i<n;++i){
            visited[i]=true;
            dfs(i,1,a[i]);
            visited[i]=false;
        }
    }
    cout<<ans;
}
