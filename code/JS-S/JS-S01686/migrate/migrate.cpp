#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6+7;
int n,s[N];ll d,a[N],f[N][3][3];
void solve(){
    scanf("%d%lld",&n,&d);
    for(int i = 1;i <= n;i++) scanf("%lld",&a[i]);
    s[n+1] = n+1,s[0] = 0;
    for(int i = n,j = n;i >= 1;i--){
        while(j > i && a[j]-a[i] > d) --j;s[i] = j;
    }ll ans = 0;
    for(int i = 1;i <= n;i++) memset(f[i],0,sizeof f[i]);
    for(int i = n;i >= 1;i--){
        if(s[i] == i) continue;
        if(s[i] == i+1){
            f[i][0][0] += f[i+1][0][0],f[i][0][1] += f[i+1][0][1]+1;
            if(s[i] > s[i-1]){
                f[i][1][0] += f[i+1][0][0],f[i][1][1] += f[i+1][0][0],f[i][1][2] += 1+f[i+1][0][1];
                f[i][2][0] += f[i+1][0][0],f[i][2][1] += f[i+1][0][0],f[i][2][2] += 1+f[i+1][0][1];
            }
            else{
                f[i][1][0] += 1+f[i+1][0][1];
                if(i > 1 && s[i-1] > s[i-2]) f[i][2][0] += 1+f[i+1][0][1];
            }
        }
        else if(s[i] >= i+2){
            int o = min(2,s[i]-i-1);
            f[i][0][0] += f[i+2][o][0],f[i][0][1] += f[i+2][o][2]+s[i]-i;
            if(s[i] > s[i-1]){
                if(s[i]-s[i-1] > 1){
                    f[i][1][0] += f[s[i]][o][0],f[i][1][1] += f[s[i]][o][0];
                    f[i][1][2] += f[s[i]][o][2]+s[i]-i;
                    f[i][2][0] += f[s[i]][o][0],f[i][2][1] += f[s[i]][o][0];
                    f[i][2][2] += f[s[i]][o][2]+s[i]-i;
                }
                else{
                    f[i][1][0] += f[s[i]][o][1]+max(s[i-1]-i,0),f[i][1][1] += f[s[i]][o][1];
                    f[i][1][2] += f[s[i]][o][2]+1;
                    if(i > 1) f[i][2][0] += f[s[i]][o][1]+max(0,s[i-1]-max(s[i-2],i));
                    f[i][2][1] += f[s[i]][o][1],f[i][2][2] += f[s[i]][o][2]+1;
                }
            }
            else{
                f[i][1][0] += f[s[i]][o][2]+s[i]-i;
                if(i > 1 && s[i-1] > s[i-2])
                    f[i][2][0] += f[s[i]][o][2]+max(0,s[i-1]-max(s[i-2],i));
            }
        }
        if(i < 3) f[i][2][0] = f[i][2][1] = f[i][2][2] = 0;
        if(i < 2) f[i][1][0] = f[i][1][1] = f[i][1][2] = 0;
        ans += f[s[i]][min(2,s[i]-i-1)][0];
    }
    printf("%lld\n",ans);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int C,T;scanf("%d%d",&C,&T);
    while(T--) solve();
    return 0;
}
