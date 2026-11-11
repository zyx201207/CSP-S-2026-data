#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],t[500002];
int f[500005];
int vis[500005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T,c;
    cin>>c>>T;
    while(T--){
        memset(vis,0,sizeof vis);
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int ans=0;
        for(int s=1;s<=n;s++){
            memset(f,0x3f,sizeof f);
            memset(vis,0,sizeof vis);
            f[s]=0;
            vis[s]=1;
            for(int i=s+1;i<=n;i++){
                int cnt=0;
                for(int j=s;j<i;j++){
                    if(a[i]-a[j]<=d){
                        if(f[i]==f[j]+1)cnt+=vis[j];
                        if(f[i]>f[j]+1){
                            cnt=vis[j];
                            f[i]=f[j]+1;
                        }
                    }
                }
                if(cnt==2){
                    ans++;
                }
                vis[i]=cnt;
            }
        }
        cout<<ans<<'\n';
    }
	return 0;
}