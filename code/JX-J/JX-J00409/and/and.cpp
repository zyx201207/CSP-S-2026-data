#include<bits/stdc++.h>
using namespace std;
const int N=2*10e5+10;
long long n,m,a[N],maxn=-1e9;
void dfs(int cnt,int last ,long long andd)
{
    if(cnt==m){
        maxn=max(maxn,andd);
        return;
    }
    for(int i=last+1;i<=n;i++){
        dfs(cnt+1,i,(cnt==0?a[i]:(andd&a[i])));
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(0,0,0);//cnt,last.and
    cout<<maxn;
}
