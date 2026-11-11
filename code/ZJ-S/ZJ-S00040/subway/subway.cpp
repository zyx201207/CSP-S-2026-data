//0(A)+0(B)pts
#include<bits/stdc++.h>
using namespace std;
vector<int>g[21][20002];
int g1[20001],g2[21][20001];
void solA(){
    int n,m,d,q;cin>>n>>m>>d>>q;
    for(int i=1;i<=n;i++)cin>>g1[i];
    for(int i=1;i<=m;i++){
        int k;cin>>k;
        for(int j=0;j<k;j++){
            int a,b;cin>>a>>b;
            g2[i][a]=b;
            g[i][n+1].push_back(a);
        }
    }
    while(q--){
        int l,r;cin>>l>>r;
        
    }
}
void solB(){
    int n,m,d,q;cin>>n>>m>>d>>q;
    for(int i=1;i<=n;i++)cin>>g1[i];
    for(int i=1;i<=m;i++){
        int k;cin>>k;
        for(int j=0;j<k;j++){
            int a,b;cin>>a>>b;
            g2[i][a]=b;
            g[i][n+1].push_back(a);
        }
    }
    while(q--){
        int l,r;cin>>l>>r;
        cout<<g2[1][l]+g2[1][r]<<'\n';
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c;cin>>c;solB();
}