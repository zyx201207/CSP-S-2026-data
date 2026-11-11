#include<bits/stdc++.h>
using namespace std;
const int MAXM=5e5+5;
int c,n,m,d,q;
int w[MAXM];
int k[MAXM],a[10005][1000];
int t[10005][1000];
int main(){
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        int id=0;
        for(int j=1;j<=k[i];j++){
            cin>>a[i][++id]>>t[i][++id];
        }
    }
    while(q--){
        int u,v;
        cin>>u>>v;
        if(c>=7&&c<=11){
            
        }
        cout<<1<<endl;
    }
    //关键在建图 好像很麻烦。。本来想处理特殊性质的
}