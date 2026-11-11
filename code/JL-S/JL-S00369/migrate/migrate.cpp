#include<bits/stdc++.h>
using namespace std;
int a[1000001];int n,m,ans;
int xhj[1000001];
struct aa{
int u,v;
};
vector<aa> k;
int main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
int t,c;
cin>>t>>c;
while(c--){
    cin>>n>>m;
    ans=0;
    for(int i=1;i<=n;i++)
        cin>>a[i];
       int o=1,oo=1,sl=1;
       while(oo<=n){
        while(oo<=n&&a[oo]-a[o]<=m){
                xhj[oo]=sl;
            oo++;
        }
        sl++;
        oo--;k.push_back({o,oo});
        o++;
        oo++;
       }
       sl--;
       for(int i=1;i<=n;i++){
        for(int j=i+2;j<=n;j+=2){
            if(xhj[i]!=xhj[j])
                ans++;
        }
       }
    cout<<ans<<'\n';
}


return 0;
}
