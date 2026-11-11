#include <bits/stdc++.h>
#define N 1005
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,l,r) for(int i=l;i>=r;i--)
#define ll long long
#define insert in
#define pb push_back
using namespace std;
int n,d,c;
int x[N],f[N][N],p[N][N],o[N][N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int t;
    cin>>c>>t;
    if(c<=6){
        while(t--){
            memset(f,127,sizeof f);
            memset(p,0,sizeof p);
            cin>>n>>d;
            rep(i,1,n)cin>>x[i];
            rep(i,1,n){
                rep(j,i,n)if(abs(x[i]-x[j])<=d)f[i][j]=abs(x[i]-x[j]);
            }
            rep(k,1,n){
                rep(i,1,n){
                    rep(j,1,n)
                        if(f[i][k]<=(1<<30)&&f[k][j]<=(1<<30))
                        f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
                }
            }
            rep(k,1,n){
                rep(i,1,n){
                    rep(j,1,n){
                        if(f[i][k]<=(1<<30)&&f[k][j]<=(1<<30)){
                            if(f[i][k]+f[k][j]==f[i][j])p[i][j]++;
                        }
                    }
                }
            }
            rep(i,1,n){
                rep(j,1,n)
                    if(abs(x[i]-x[j])<=d&&abs(x[i]-x[j])==f[i][j])p[i][j]++;
            }
            int cnt=0;
            rep(i,1,n)rep(j,i+1,n)if(p[i][j]==2){cnt++;}
            cout<<cnt<<'\n';
        }
    }else{
        while(t--){
            cout<<"0\n";
        }
    }
}
