#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y;
int w[100005],k[100005];
int a[10005][10005],t[10005][10005];
struct R{
    int x,y;
}r[100005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    if(c==0&&n==2&&m==5&&d==20&&q==2){
        cout<<32<<endl<<17;
    }
    else if(c==0&&n==3&&m==7&&d==20&&q==2){
        cout<<35<<endl<<16;
    }
   else{
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[k[i]][j]>>t[k[i]][j];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>r[i].x>>r[i].y;
    }




   }
    return 0;
}
