#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
    int x,y;
int w[500067];
int k[512];
int ti[500067];
vector<int>a[512],t[512],l[500067];
map<int,int>p[512];
void dfs(int x,int t,int l,int dist){
    ti[x]=dist;
    if(t=y){
        cout<<dist;return;
    }
    for(int i=0;i<l[x].size();i++){
        if(ti[a[i][p[i][x]+1]]>dist+t[l][x]+t[i][a[i][p[i][x]+1]])
        dfs(a[i][p[i][x]+1],y,i,dist+t[l][x]+t[i][a[i][p[i][x]+1]]);
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++){
        cin>>k[i];int zz;
        for(int j=0;j<k[i];j++){
            cin>>zz;
            a[i].push_back(zz);//a[line][position]=station
            l[zz].push_back(i);// l[station]=lines
            p[i][zz]=j;
            cin>>zz;
            t[i].push_back(zz);//p[line][station]=position
        }
    }
    while(q--){
        for(int i=1;i<=m;i++)time[i]=2067676767;
        cin>>x>>y;
        for(int i=0;i<l[x].size();i++){
            dfs(x,y,l[x][i],0)
        }
    }
    return 0;
}
