#include<iostream>
#include<vector>
#define ll unsigned long long
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,n;
    ll d;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;

        vector<ll> x(n+2);
        vector<int> ft(n+1);
        vector<vector<ll> > dis(n+1);
        for(int i=1;i<=n;i++) cin>>x[i];
        x[n+1]=x[n];
        ll ans=0;
        ll dist=0;
        bool flag=1;
        for(int i=1,j=1;i<=n;i++){
            if(i>=2) dist-=(x[i]-x[i-1]);
            while(dist<=d &&j<=n&&flag) {
                j++; dist+=x[j]-x[j-1];
                if(dist<=d && j>n) {
                    flag=0;j--;
                }
            }
            if(flag){
                j--; dist-=x[j]-x[j-1];
            }
            ft[i]=j;
        }

        //for(int i=1;i<=n;i++) cout<<ft[i]<<" ";
        for(int u=1;u<=n;u++){
            dis[u].resize(n+1);
            int uu=u,uuu=u,m=0;
            while(uu<n){
                uuu=uu;uu=ft[uu];m++;
                for(int i=uuu+1;i<=uu;i++) dis[u][i]=m;
            }
        }
        //for(int u=1;u<=n;u++){
        //   for(int i=u+1;i<=n;i++) cout<<dis[u][i]<<" ";
        //  cout<<endl;
        //}
        vector<vector<int> > ch(n+1);
        for(int i=1;i<=n;i++){
            ch[i].resize(n+1);
            for(int j=1;j<=n;j++) ch[i][j]=0;
        }
        for(int i=3;i<=n-1;i++){
            for(int u=1;u<=n-3;u++){
                int v=u+i;
                int r=0;
                ll dd=dis[u][v];
                for(int k=u+1;k<=v-1;k++){
                    if(dis[u][k]+dis[k][v] == dd) r++;
                }
                if(r==2) ans++;
                if(r>2) ch[i][u]=1;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
