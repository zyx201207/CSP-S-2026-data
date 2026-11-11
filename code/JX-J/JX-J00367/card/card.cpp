#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],ans[300010];
bool bb=1,oe[300010];
void solve1(){
    for(int i=1;i<=n;i++){
        vector<int>z;
        for(int j=i;j<=n;j++){
            for(int k=0;k<z.size();k++){
                if(z[k]==a[j]){
                    for(;z[z.size()-1]!=a[j];z.pop_back());
                    z.pop_back();
                    break;
                }
            }
            z.push_back(a[j]);
        }
        for(auto j:z){
            ans[j]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
}
void solve2(){
    for(int i=1;i<=n;i++){
        ans[a[i]]=i;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i-1]>a[i]){
            bb=0;
        }
    }
    solve2();
    return 0;
    if(n<=500){
        solve1();
    }
    else{
        if(bb){
            solve2();
        }
    }
    return 0;
}
