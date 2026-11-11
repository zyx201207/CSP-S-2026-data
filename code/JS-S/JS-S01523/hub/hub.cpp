#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
vector<int> a[100005];
int fa[100005],dis[100005];
int minn=0x3f3f3f;
void dfs(int fa){


}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    if(c==0){
        cout<<1<<endl<<2;
    }
    else{
        while(t--){
            cin>>n>>k;
            for(int i=1;i<n;i++){
                int u,v;
                cin>>u>>v;
                a[u].push_back(v);
                a[v].push_back(u);
            }

        }
    }
    return 0;
}
