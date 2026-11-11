#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long c[500005],vis[500005],ans[500005];
vector<long long>v;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){cin>>c[i];}
    ans[c[n]]++;
    for(int i=1;i<n;i++){
        v.push_back(c[i]);
        vis[c[i]]++;
        for(int j=i+1;j<=n;j++){
            if(vis[c[j]]==0){
                v.push_back(c[j]);
                vis[c[j]]++;
            }
            else{
                while(v.back()!=c[j]){
                    vis[v.back()]--;
                    v.pop_back();
                }
            }
        }
        while(!v.empty()){
            ans[v.back()]++;
            vis[v.back()]--;
            v.pop_back();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
