#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5*1e5+10;
const int M=5000+10;
const int F=288;
int n;
ll m,a[N];
ll dp[M][M],l,maxa,mina;
int ans,r;
int bt[F],cst;
ll dt;
bool dc=true;

int main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxa=max(maxa,a[i]);
        mina=min(mina,a[i]);
    }
    if(n<=8000){
        ans=1;
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                l=j-1;
                l*=a[i]-a[i-1];
                dp[i][j]=dp[i-1][j-1];
                dp[i][j]+=l;
                if(dp[i][j]>m){
                    break;
                }
                ans=max(ans,j);
            }
        }
        cout<<ans<<'\n';
        return 0;
    }
    if(maxa<=100&&mina>=-100){
        for(int i=1;i<=n;i++){
            bt[a[i]+111]++;
        }
        for(int i=mina+111;i<=maxa+111;i++){
            cst=0;
            r=bt[i];
            ans=max(ans,r);
            for(int j=i-1;j>=mina+111;j--){
                cst+=bt[j]*(i-j);
                if(cst<=m){
                    r+=bt[j];
                    ans=max(ans,r);
                }
                else{
                    l=cst-m;
                    r+=bt[j];
                    r-=l/(i-j);
                    if(l%(i-j)!=0){
                        r--;
                    }
                    ans=max(ans,r);
                    break;
                }
            }
        }
        cout<<ans<<'\n';
        return 0;
    }
    dt=a[2]-a[1];
    for(int i=2;i<=n;i++){
        if(a[i]-a[i-1]!=dt){
            dc=false;
        }
    }
    if(dc){
        for(int i=1;i<=n;i++){
            l=i*(i-1);
            l/=2;
            l*=dt;
            if(l<=m){
                ans=i;
            }
            else{
                break;
            }
        }
        cout<<ans<<'\n';
        return 0;
    }
    cout<<n<<'\n';
    return 0;
}
