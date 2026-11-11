#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,time[100010];
struct xl{
    int a,t;
}line[520][500010];
struct plan(){
    int x,y;
}r[100010];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    vector<long long> w(m);
    for(int i=0;i<m;i++) scanf("%lld",&w[i]);
    for(int i=0;i<n;i++){
        int k1=0;
        scanf("%d",k1);
        for(int j=0;j<k1;j++) scanf("%d%d",&line[i][j].a,&line[i][j].t);
    }
    for(int i=0;i<q;i++){scanf("%d%d",&r[i].x,&r[i].y); time[i]+=(r[i].x+r[i].y);}

    for(int i=0;i<q;i++) printf("%d\n",time[i]);
}
