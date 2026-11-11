#include<bits/stdc++.h>
using namespace std;
int ccfnb,n,m,d,q,w[150010],t1,t2,xx,yy;
struct aaa{
    int x,y,t,vis;
}a[500010];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >>ccfnb>>n>>m>>d>>q;

    for(int i=1;i<=m;i++) cin >>w[i];
    for(int i=1;i<=n;i++){
        cin >>ccfnb>>a[i].x>>t1>>a[i].y>>t2;
        a[i].t=t1+t2;
    }

    while(q--){
        long long s=0;
        for(int i=1;i<=n;i++) a[i].vis=0;
        cin >>xx>>yy;
        if(xx>yy) swap(xx,yy);
        for(int i=xx;i<yy;i++) s+=a[i].t;
        cout <<s+w[xx]+w[yy]<<endl;
    }
    return 0;
}
