#include<bits/stdc++.h>
using namespace std;
int n,m;
bool vis[300005];
int a[500005];
int cnt[300005];
vector<int>table;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int k=1;k<=n;k++){
        table.clear();
        memset(vis,false,sizeof(vis));
        for(int i=k;i<=n;i++){
            if(vis[a[i]]){
                while(table[table.size()-1]!=a[i]){
                    vis[table[table.size()-1]]=false;
                    table.pop_back();
                }
            }else{
                table.push_back(a[i]);
                vis[a[i]]=true;
            }
        }
        for(int i=0;i<table.size();i++)cnt[table[i]]++;
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
    return 0;
}
