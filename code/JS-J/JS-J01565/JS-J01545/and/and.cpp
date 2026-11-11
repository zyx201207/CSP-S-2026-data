#include<bits/stdc++.h>
using namespace std;
const long long N=200005;
long long n,m,maxn=-1;
long long a[N];
bool vis[N];
void f(long long cnt,long long sum){
    if(cnt==m){
        maxn=max(maxn,sum);
        return ;
    }
    for(long long i=1;i<=n;++i){
        if(!vis[i]){
            long long t=sum;
            long long t1=a[i];
            long long c=t & t1;
            vis[i]=1;
            f(cnt+1,c);
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;++i){
        cin>>a[i];
    }
    for(long long i=1;i<=n;++i){
        memset(vis,false,sizeof(vis));
        vis[i]=1;
        f(1,a[i]);
    }
    cout<<maxn<<endl;
    return 0;
}
