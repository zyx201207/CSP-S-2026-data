#include<bits/stdc++.h>
using namespace std;
int c,m,n,d,q,k;
long long w[500005];
struct sj{
   long long t;
   int a,x,y;
   }p[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>p[j].a>>p[j].t;
            }
    }
     for(int z=1;z<=q;z++){
            cin>>p[z].x>>p[z].y;
        }


    //ji de qu xiao zhu shi
return 0;}
