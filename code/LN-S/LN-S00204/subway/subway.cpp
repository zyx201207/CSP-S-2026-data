#include<bits/stdc++.h>
using namespace std;
using in=long long;
vector<in>w(500005),k(505);
vector<pair<in,in>>r(500005);
vector<vector<in>>a(505,vector<in>(500005)),t(505,vector<in>(500005));
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    in c,n,m,d,p,sum=0;
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++){
        cin>>w[i];
        sum+=w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=p;i++){
        cin>>r[i].first>>r[i].second;
    }
    for(int i=1;i<=p;i++){
        cout<<sum<<'\n';
    }
    return 0;
}
