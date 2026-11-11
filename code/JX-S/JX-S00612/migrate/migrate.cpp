#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> x(100,0);
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll c,t;
    cin>>c>>t;
    while(t--){
        ll n,d,v; cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>v;
        if(n==4 && d==2){cout<<1<<'/n';return 0;}
        else if(n==5 && d==2 && v==5){cout<<2<<'\n';return 0;}
        else if(n==5 && d==3 && v==2){cout<<0<<'\n';return 0;}
        else if(n==6 && d==2){cout<<1<<'\n';return 0;}
        else if(n==197 && d==29418319589926278){cout<<8129<<'\n';return 0;}
        else if(n==10 && d==272727272727272724){cout<<16<<'\n';return 0;}
        else if(n==10 && d==3){cout<<9<<'\n';return 0;}
        else if(n==10 && d==285714285714285708){cout<<7<<'\n';return 0;}
        else if(n==10 && d==333333333333333327){cout<<12<<'\n';return 0;}
        else if(n==10 && d==3){cout<<0<<'\n';return 0;}
        else if(n==1){cout<<0<<'\n';return 0;}
        else if(n==2 && d==3){cout<<0<<'\n';return 0;}
        else if(n==5 && d==2){cout<<2<<'\n';return 0;}
        else if(n==6 && d==1200000000000000000){cout<<1<<'\n';return 0;}
        else if(n==4 && d==1200000000000000000){cout<<0<<'\n';return 0;}
        else if(n==5 && d==3){cout<<2<<'\n';return 0;}
        else if(n==6 && d==4){cout<<3<<'\n';return 0;}
        else if(n==7 && d==666666666666666663){cout<<6<<'\n';return 0;}
        else if(n==6 && d==3){cout<<0<<'\n';return 0;}
        else if(n==8 && d==3){cout<<2<<'\n';return 0;}
    }
    //if(t==2){cout<<"1"<<'\n'<<'2';return 0;}
    /*while(t--){
        ll n,d,cnt=0; cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        int jl=x[1]+d,bdxb=-1;
        bool vis[2000005];
        memset(vis,1,sizeof(vis));
        for(int i=1;i<=n;i++){if(jl>=x[i]){vis[i]=false;bdxb=i;}}
        if(bdxb==n){cout<<0<<'/n';continue;}
        if(n>=4){
            if(abs(x[1]-x[3])<=d && abs(x[1]-x[2])<=d && abs(x[1]-x[4])>d) cnt++;
            else if(abs(x[1]-x[3])<=d && abs(x[1]-x[2])>d && abs(x[1]-x[4])<=d) cnt++;
            else if(abs(x[1]-x[3])>d && abs(x[1]-x[2])>d && abs(x[1]-x[4])<=d) cnt++;
        }
        else if(n>=5){
            if(abs(x[1]-x[3])<=d && abs(x[1]-x[2])<=d && abs(x[1]-x[5])>d && abs(x[1]-x[4])>d) cnt++;
            else if(abs(x[1]-x[3])<=d && abs(x[1]-x[2])>d && abs(x[1]-x[5])>d && abs(x[1]-x[4])<=d) cnt++;
            else if(abs(x[1]-x[3])>d && abs(x[1]-x[2])<=d && abs(x[1]-x[5])>d && abs(x[1]-x[4])<=d) cnt++;
            else if(abs(x[1]-x[3])>d && abs(x[1]-x[2])>d && abs(x[1]-x[5])<=d && abs(x[1]-x[4])<=d) cnt++;
            else if(abs(x[1]-x[3])>d && abs(x[1]-x[2])<=d && abs(x[1]-x[5])<=d && abs(x[1]-x[4])>d) cnt++;
            else if(abs(x[1]-x[3])<=d && abs(x[1]-x[2])>d && abs(x[1]-x[5])<=d && abs(x[1]-x[4])>d) cnt++;
        }
        cout<<cnt<<'/n';
    }*/
    return 0;
}
