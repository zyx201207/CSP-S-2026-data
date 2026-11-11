#include<bits/stdc++.h>
using namespace std;
int x,y,k,c,n,m,d,q,w[300000];
struct{
    int a,t;
}g[300000];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++)cin>>w[i];
    cin>>k;
    for(int i=0;i<k;i++)cin>>g[i].a>>g[i].t;
    cin>>x>>y;
    return 0;
}
