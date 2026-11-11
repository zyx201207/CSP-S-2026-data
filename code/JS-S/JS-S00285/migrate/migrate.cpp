#include<bits/stdc++.h>
#define int long long 
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
using namespace std;
void solve(){
    int n,d;
    cin>>n>>d;
    vector<int>x(n);
    for(auto&i:x)cin>>i;
    vector<vector<int>>f(n,vector<int>(n,4e18)),h(n,vector<int>(n,0));
    int ans=0;
    for(int i=0;i<n;i++){
        f[i][i]=0,h[i][i]=1;
        for(int j=i+1;j<n;j++){
            for(int k=i;k<j;k++)if(x[k]+d>=x[j]){
                if(f[i][k]+1<f[i][j])f[i][j]=f[i][k]+1,h[i][j]=h[i][k];
                else if(f[i][k]+1==f[i][j])h[i][j]+=h[i][k];
            }
            if(h[i][j]==2)ans++;
        }
    }
    cout<<ans<<endl;
}
signed main(){
    file("migrate");
    int c,t;
    cin>>c>>t;
    while(t--)solve();
}