#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int ans[300010];
bool vis[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int j=1;j<=n;j++){
        vector<int>s;
        fill(vis+1,vis+300005,false);
        for(int i=j;i<=n;i++){
            if(!vis[a[i]]){
                s.push_back(a[i]);
                vis[a[i]]=true;
            }
            else{
                while(!s.empty()&&s[int(s.size())-1]!=a[i]){
                    vis[s[int(s.size())-1]]=false;
                    s.pop_back();
                }
            }
        }
        for(int i=0;i<=int(s.size())-1;i++){
            ans[s[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
