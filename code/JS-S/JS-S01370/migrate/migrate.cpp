#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=5e2+5,M=5e5+5;
vector<int> a;
int n,m;
int dfs(int i,int cn,int des){
    if(i==n){
        return cn;
    }
    int ans=0;
    for(int j=i+1;j<=n;j++){
        if(a[j]-a[i]>m)break;
        ans=max(dfs(j,cn+1,des),ans);
    }
    return ans;
}
void solve(){
    cin>>n>>m;
    a.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int cn=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(dfs(i,0,j)==2)cn++;
        }
    }
    cout<<cn<<endl;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t=1,c;
    cin>>c>>t;
    while(t--)solve();
    return 0;
}