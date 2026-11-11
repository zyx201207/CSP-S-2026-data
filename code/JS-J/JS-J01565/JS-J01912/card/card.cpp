#include<bits/stdc++.h>
using namespace std;
int a[500005];
int cnt[500005];
bool vis[500005];
vector <int> v[500005];
void check(int n,int x){
    int w=-1;
    for(int i=0;i<v[x].size()-1;i++){
        if(v[x][i]==n){
            w=i;
        }
    }
    if(w==-1){
        return ;
    }else{
        for(int i=w;i<v[x].size()-1;i++){
            v[x][i]=-1;
        }
    }
}
int main(){
//    freopen("card.in","r",stdin);
//    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
            memset(vis,0,sizeof(vis));
        for(int j=i;j<=n;j++){
            v[i].push_back(a[j]);
            check(a[j],i);
        }
        for(int j=0;j<v[i].size();j++){
            if(v[i][j]!=-1&&vis[j]!=1){
                cnt[v[i][j]]++;
                vis[v[i][j]]=1;
            }
        }
        cout<<endl;
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
