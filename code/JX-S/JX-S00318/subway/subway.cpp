#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,t,ans,a[500010],b[1010][1010],xx,yy;
int qwe(int x,int y){
    int ans=0;
    for(int i=x;i<=y;i++){
        ans+=b[i][1]+b[i][2];
    }
    return ans;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>t;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    int q,x,y,s,h;
    for(int i=1;i<=n;i++){
        cin>>q>>x>>y>>s>>h;
        b[q][1]=y;
        b[q][2]=h;
    }
    int ans=0;
    for(int i=1;i<=t;i++){
        ans=0;
        cin>>xx>>yy;
        ans+=qwe(xx,yy)+a[xx]+a[yy];
        cout<<ans<<"\n";
    }
    return 0;
}
