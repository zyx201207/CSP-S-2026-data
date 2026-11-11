#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int m,n;
bool vis[maxn];
long long mm=-1;
long long  a[maxn],b[maxn],ds[maxn];
long long ans(long long a,long long b){
    if(a==b){
        return a;
    }
    if(a>b){
        return b;
    }
    if(a<b){
        return a;
    }
}
void dfs(long long x){
    if(x>m){
        for(int i=0;i<m;i++){
            mm=max(mm,ans(a[i],a[i+1]));
        }
        return;
    }
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            vis[i]=1;
            a[x]=b[i];
            dfs(x+1);
            vis[i]=0;
        }

    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    dfs(0);
    cout<<mm;
    return 0;
}
/*


*/
