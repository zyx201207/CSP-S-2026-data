#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[2000005],ans,c,q,d;
int f[5005][5005];
void work(int x){
    memset(f,0,sizeof f);
    f[x][0]=1;
    for(int i = x;i<=n;i++){
        for(int j = n;j>=0;j--){
            for(int k = i+1;k<=n;k++){
                if(a[k]-a[i]>d)
                    break;
                f[k][j+1]+=f[i][j];
            }
        }
    }
    for(int i = x;i<=n;i++){
        for(int j = 0;j<=n;j++)
        if(f[i][j]!=0){
            if(f[i][j]==2)ans++;
            break;
        }
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(cin>>c>>q;q;q--,ans=0){
    cin>>n>>d;
    cin>>a[1];
    for(int i = 2;i<=n;i++)
        cin>>a[i];
    if(n==1){
        cout<<0<<"\n";
        continue;
    }
    if(c>=11&&c<=12){
    int f=0;
    for(int i = 1;i<=n-3;i++,f=0){
        for(int j = i;j<i+3;j++)
            if(a[j+1]-a[j]>d)
                f=1;
        if(f==0&&a[i+2]-a[i]<=d&&a[i+3]-a[i+1]<=d&&a[i+3]-a[i]>d)
            ans++;
        }
        cout<<ans<<"\n";
        continue;
    }

    for(int i = 1;i<=n;i++)
        work(i);
     cout<<ans<<"\n";

    }

    return 0;
}


