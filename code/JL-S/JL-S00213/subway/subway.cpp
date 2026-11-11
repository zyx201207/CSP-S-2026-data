#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
int a[N][N],t[N][N],w[N];
int n,m,d,q,k;
vector<int> cheq,kj;
map<int,vector<int> > ma;
int miN=1e9;
void dfs1(int x,int y,int ji,int now){
    for(int i=0;i<cheq.size();i++){
        if(now==cheq[i]) return;
    }
    if(now==y){
        miN=min(ji,miN);
        return;
    }
    for(int j=0;j<ma[now].size();j++){
        ji+=t[ma[now][j]][now];
        for(int i=0;i<kj[ma[now][j]];i++){
            cheq.push_back(a[ma[now][j]][i]);
            dfs1(x,y,ji,a[ma[now][j]][i]);
        }
    }
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int dddd;
    cin>>dddd;
    cin>>n>>m>>d>>q;
    for(int i=0;i<m;i++){
        cin>>w[i];
    }
    for(int j=0;j<n;j++){
        int l;
        cin>>l;
        kj.push_back(l);
        for(int i=0;i<l;i++){
            cin>>a[j][i]>>t[j][i];
            ma[a[j][i]].push_back(i+1);
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        dfs1(x,y,w[x-1],1);
        miN+=w[y-1];
        cout<<miN;
    }
}
