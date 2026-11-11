#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200010][35],maxn=-1,flag[200005],po[35],ans=0,k[200005];
void pre(){
    po[0]=1;
    for(int i=1;i<=32;i++){
        po[i]=po[i-1]*2;
    }
    for(int i=1;i<=200005;i++){
        for(int j=1;j<=35;j++){
            a[i][j]=0;
        }
    }
}
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    memset(flag,-1,sizeof(flag));
    pre();
    for(int i=1;i<=n;i++){
        cin>>k[i];
    }
    for(int i=1;i<=n;i++){
        int s=0;
        while(k[i]!=0){
            s++;
            if(k[i]%2==1) a[i][s]=1;
            else a[i][s]=0;
            k[i]/=2;
        }
        maxn=max(maxn,s);
    }
    for(int i=maxn;i>=1;i--){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(a[j][i]==1&&flag[j]==-1) cnt++;
        }
        if(cnt>=m){
            for(int j=1;j<=n;j++){
                if(a[j][i]==0) flag[j]=1;
            }
            ans+=po[i-1];
        }
    }
    cout<<ans<<endl;
    return 0;
}
