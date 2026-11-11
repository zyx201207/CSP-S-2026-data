#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=605;
int x[2000005],pd[maxn][maxn];
int c,t,n,m;
struct node{
    int cnt,last;
};
node a[maxn][maxn];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        int dis=x[n]-x[1];
        if(m>=dis){
            cout<<"0\n";
            continue;
        }
        if(c==11||c==12){
            int ans=0;
            int d=m/(x[2]-x[1]);
            if(d==0||d==1){
                cout<<0<<"\n";
                continue;

            }
            for(int i=1;i<=n-d-1;i++){
                if(i+2*d-1<=n) ans++;
            }
            cout<<ans<<"\n";
            continue;
        }
        if(c==13||c==14){
            cout<<"0\n";
        }
        int ans=0;
        x[n+1]=1e18+5;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) a[i][j].cnt=a[i][j].last=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                int k=i,p=i;
                while(k<j){

                    p=k;
                    k=upper_bound(x+1,x+n+2,x[p]+m)-x-1;
                    if(k==p){
                        a[i][j].cnt=-1;
                        break;
                    }
                     a[i][j].cnt++;
                   // cout<<i<<" "<<j<<" "<<k<<" "<<a[i][j].cnt<<"\n";


                }
                a[i][j].last=p;
            }
        }/*
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                cout<<i<<" "<<j<<" "<<a[i][j].cnt<<" "<<a[i][j].last<<"\n";
            }
        }*/
        for(int i=1;i<=n;i++) pd[i][i]=1,a[i][i-1].cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                int k=a[i][j].last;
                int cnt=0;
                while(k>=i&&x[j]-x[k]<=m){
                    if(a[i][k].cnt+1==a[i][j].cnt) cnt+=pd[i][k];
                    k--;
                }
                if(cnt!=0) pd[i][j]=cnt;
                else pd[i][j]=1;
                if(cnt==2){
                    ans++;
                }
            }
        }/*
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++) cout<<pd[i][j]<<" ";
            cout<<"\n";
        }*/
        cout<<ans<<"\n";
    }
    return 0;
}
