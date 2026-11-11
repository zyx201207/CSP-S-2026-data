#include <bits/stdc++.h>
using namespace std;
const int N=2e3+5;
vector <int> T[N];
long long c,n,d,t,a[N],sum[N],cnt;
void dfs(int l,int r){
    if(l==r){
        return;
    }
    for(auto v:T[l]){
        cnt++;
        dfs(v,r);
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){
        int cnt=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i-1;j++){
                if(a[i]-a[j]<=d){
                    cout<<j<<' '<<i<<'\n';
                    T[j].push_back(i);
                }
            }
            cout<<'\n';
        }
        for(int i=1;i<=n;i++){
            for(auto v:T[i]) cout<<v<<' ';
            cout<<'\n';
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                memset(sum,0,sizeof(sum));
                int cnt=0;
                if((a[j]-a[i])<=d||(a[j]-a[i])%d==0) continue;
                dfs(i,j);
                cout<<cnt<<'\n';
            }
        }
    }
    return 0;
}
