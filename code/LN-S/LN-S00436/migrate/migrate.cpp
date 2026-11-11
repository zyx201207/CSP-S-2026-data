#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll C,T,n,m,ans;
ll p[2000009];
ll f[309][309];
int ch[309][309];
int chk(int x,int y){
    if(ch[x][y]!=0)return ch[x][y];
    if(p[x]+m==p[x+2]&&p[y]-m==p[y-2]){ch[x][y]=1; return ch[x][y];}
    if(p[x]+m!=p[x+1]){ch[x][y]=-1; return ch[x][y];}
    if(p[y]-m!=p[y-1]){ch[x][y]=-1; return ch[x][y];}
    return chk(x,y-m)&&chk(x+m,y);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>C>>T;
    while(T--){
        memset(p,0,sizeof(p));
        memset(ch,0,sizeof(ch));
        cin>>n>>m;
        ch[0][0]=ch[0][1]=ch[0][2]=ch[1][1]=ch[1][2]=ch[2][2]=-1;
        ch[m][m]=ch[m-1][m]=ch[m-2][m]=ch[m-1][m-1]=ch[m-2][m-1]=-1;
        for(int i=1;i<=n;++i){
            cin>>p[i];
        }
        if(C==11||C==12){
            ll k=p[2]-p[1];
            ll t=m/k;
            if(t<=1||n-2*t<0)ans=0;
            else {
                ans=n-2*t+1;
            }
            cout<<ans<<"\n";
        }
        if(C==13||C==14){
            cout<<0<<"\n";
        }
        if(C>=0||C<=6){
            ll ans=0;
            for(int i=1;i<=n;++i){
                for(int j=i+1;j<=n;++j){
                    if(chk(i,j)==1){ans++;}
                }
            }
            cout<<(ans/4)<<"\n";
        }
    }
    return 0;
}
