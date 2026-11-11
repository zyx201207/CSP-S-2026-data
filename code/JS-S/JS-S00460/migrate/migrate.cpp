#include<bits/stdc++.h>
using namespace std;
ifstream fin("migrate.in");
ofstream fout("migrate.out");
#define int long long
#define cin fin
#define cout fout
int x[5005];
int dp[5005][5005];
int f[5005][5005];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _,T;
    cin>>_>>T;
    if(_<=10){
        while(T--){
            int n,m;
            cin>>n>>m;
            for(int i=1;i<=n;++i) cin>>x[i];
            for(int i=1;i<=n;++i)
                for(int j=i+1;j<=n;++j){
                    dp[i][j]=1145141919810ll;
                    f[i][j]=0;
                }
            for(int i=1;i<=n;++i) f[i][i]=1;
            int s=0;
            for(int len=1;len<=n;++len)
                for(int i=1;i+len<=n;++i){
                    int j=i+len;
                    for(int k=i;k<j;++k)
                        for(int l=k+1;l<=j;++l)
                            if(x[j]-x[k]<=m) dp[i][j]=min(dp[i][j],dp[i][k]+dp[l][j]+1);
                    for(int k=i;k<j;++k)
                        for(int l=k+1;l<=j;++l)
                            if(x[j]-x[k]<=m&&dp[i][j]==dp[i][k]+dp[l][j]+1)
                                f[i][j]+=f[i][k]*f[l][j];
                    if(f[i][j]==2) s++;
                }
            // for(int i=1;i<=n;++i){
            //     for(int j=1;j<=n;++j) cout<<f[i][j]<<" ";
            //     cout<<"\n";
            // }
            cout<<s<<"\n";
        }
    }
    else if(_==11||_==12){
        while(T--){
            int n,m;
            cin>>n>>m;
            for(int i=1;i<=n;++i) cin>>x[i];
            int d=x[2]-x[1];
            int k=m/d;
            cout<<max(0ll,n-2*k+1)*(k>=2)<<"\n";
        }
    }
    else if(_==13||_==14){
        while(T--){
            int n,m;
            cin>>n>>m;
            for(int i=1;i<=n;++i) cin>>x[i];
            int ks=-1;
            int kkk=0;
            for(int i=1;i<=n;++i) if(x[i]-x[1]<=m||x[n]-x[i]<=m){
                ks=i;
                kkk++;
            }
            if(kkk>=2){
                cout<<"0\n";
                continue;
            }
            int r=ks+1;
            int R=ks+1;
            int resss=0;
            for(int l=1;l<ks;++l){
                int ss=0;
                if(x[ks-1]-x[l]<=m&&x[r]-x[ks-1]<=m) ss++;
                if(x[ks+1]-x[l]<=m&&x[r]-x[ks+1]<=m) ss++;
                if(l<=ks-2&&x[ks-2]-x[l]<=m&&x[r]-x[ks-2]<=m) ss++;
                if(r>=ks+2&&x[ks+2]-x[l]<=m&&x[r]-x[ks+2]<=m) ss++;
                while(r<=n&&((x[r]-x[l]<=m)||ss>1)){
                    r++;
                    ss=0;
                    if(x[ks-1]-x[l]<=m&&x[r]-x[ks-1]<=m) ss++;
                    if(x[ks+1]-x[l]<=m&&x[r]-x[ks+1]<=m) ss++;
                    if(l<=ks-2&&x[ks-2]-x[l]<=m&&x[r]-x[ks-2]<=m) ss++;
                    if(r>=ks+2&&x[ks+2]-x[l]<=m&&x[r]-x[ks+2]<=m) ss++;
                }
                ss=0;
                R=r;
                if(x[ks-1]-x[l]<=m&&x[R]-x[ks-1]<=m) ss++;
                if(x[ks+1]-x[l]<=m&&x[R]-x[ks+1]<=m) ss++;
                if(l<=ks-2&&x[ks-2]-x[l]<=m&&x[R]-x[ks-2]<=m) ss++;
                if(R>=ks+2&&x[ks+2]-x[l]<=m&&x[R]-x[ks+2]<=m) ss++;
                while(R<=n&&((x[R]-x[l]<=m)||ss>1)){
                    R++;
                    ss=0;
                    if(x[ks-1]-x[l]<=m&&x[R]-x[ks-1]<=m) ss++;
                    if(x[ks+1]-x[l]<=m&&x[R]-x[ks+1]<=m) ss++;
                    if(l<=ks-2&&x[ks-2]-x[l]<=m&&x[R]-x[ks-2]<=m) ss++;
                    if(R>=ks+2&&x[ks+2]-x[l]<=m&&x[R]-x[ks+2]<=m) ss++;
                }
                resss+=R-r;
            }
            cout<<resss<<"\n";
        }
    }
    return 0;
}
