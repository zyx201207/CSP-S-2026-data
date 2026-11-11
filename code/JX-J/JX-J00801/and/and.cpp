#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
bool f[200005];
map<int,vector<int> > ma;
long long g[100];
long long ans;
bitset<32> b[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    g[0]=1;
    for(int i=1;i<=32;i++){
        g[i]=g[i-1]*2;
    }
    for(int i=0;i<=31;i++){
        for(int j=1;j<=n;j++){
            if(b[j][i]==1){
                ma[i].push_back(j);
            }
        }
    }
    for(int i=31;i>=0;i--){
        if(ma[i].size()<m)continue;
        int cc=i;
        bool fl[200005]={0};
        int k=0;
        for(auto it:ma[i]){
            if(f[it])continue;
            fl[it]=1;
            k++;
        }
        if(k>=m){
            ans+=g[cc];
        }
        for(int j=1;j<=n;j++){
            if(f[j])continue;
            if(fl[j])continue;
            f[j]=1;
        }
    }
    cout<<ans;
    return 0;
}
