#include <bits/stdc++.h>
using ll=long long;
using namespace std;
constexpr int MAXN=5005;
ll f[MAXN][MAXN],arr[MAXN],fcnt[MAXN][MAXN];
int main(){
    FILE* _f=freopen("migrate.in","r",stdin);
    _f=freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--){
        memset(f,0x3f,sizeof(f));
        int n;
        ll d;
        cin>>n>>d;
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=0;i<n;i++) for(int j=i;j<n;j++){
            if(i==j){
                f[i][j]=0;
                continue;
            }
            if(arr[j]-arr[i]<=d){
                f[i][j]=1;
                fcnt[i][j]=1;
            }else fcnt[i][j]=0;
        }
        for(int k=1;k<n;k++) for(int i=0;i<=k;i++) for(int j=i+1;j<=k;j++){
            ll t=f[i][k]+f[j][k];
            if(t<f[i][j]){
                f[i][j]=t;
                fcnt[i][j]=1;
            }else if(t==f[i][j]) ++fcnt[i][j];
        }
        ll res=0;
        for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) if(fcnt[i][j]==2) ++res;
        cout<<res<<'\n';
    }
    return 0;
}