#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define int long long
int n,m,ma;
vector<int> a,used,b;
void dfs(int dep){
    if(dep>m){
        int sum=b[1];
        for(int i=2;i<=m;i++)sum=sum&b[i];
        ma=max(ma,sum);
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!used[i]){
            used[i]=true;
            b[dep]=a[i];
            dfs(dep+1);
            used[i]=false;
        }
    }
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    a.resize(n+5),b.resize(n+5),used.resize(n+5);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dfs(1);
    cout<<ma;
    return 0;
}
