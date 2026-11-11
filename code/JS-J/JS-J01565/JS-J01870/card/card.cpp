#include<bits/stdc++.h>
using namespace std;
int n,m,a[500100],vis1[500100],ans[500100],vis2[300100];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        vector<int> res;
        for(int j=i;j<=n;j++){
            int cur=a[j];
            if(vis1[cur]==0){
                res.push_back(cur);
                vis2[cur]=res.size();
            }
            else{
                for(int k=vis2[cur];k<res.size();k++){
                    vis1[res[k]]=0;
                }
                res.resize(vis2[cur]);
            }
            vis1[cur]=1;
        }
        for(int j=0;j<res.size();j++){
            ans[res[j]]++;
        }
        for(int j=1;j<=n;j++){
            vis1[j]=0;
        }
    }
    for(int j=1;j<=m;j++){
            cout<<ans[j]<<" ";
    }
}
