#include<bits/stdc++.h>
using namespace std;
constexpr int maxn=1e6+7;
int c,t,n,k;
int u,v;
vector<int>S[maxn],E[maxn];
int f[maxn];
int max_h,max_pos;
int max_num;
void dfs(int pos,int fa=0,int H=0){
    if(max_h<H){
        max_h=H;
        max_pos=pos;
    }
    for(auto i:S[pos]){
        if(i==fa)continue;
        dfs(i,pos,H+1);
    }
}
void dfs1(int pos,int fa=0,int H=0){
    if(max_h<H){
        max_h=H;
        max_num=1;
    }else{
        if(max_h==H){
            max_num++;
        }
    }
    for(auto i:S[pos]){
        if(i==fa)continue;
        dfs1(i,pos,H+1);
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            cin>>u>>v;
            S[u].push_back(v);
            S[v].push_back(u);
        }
        dfs(1);
        max_h=0;
        dfs1(max_pos);
        max_num++;
        if(k==2){
            if(max_num==2){
                cout<<((max_h-2)/3)+((max_h-2)%3==0)<<'\n';
            }else{
                if(max_h&1){
                    cout<<(max_h>>1)<<'\n';
                }else{
                    cout<<(max_h>>1)<<'\n';
                }
            }
        }
    }
}