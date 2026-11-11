#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
const int N=2e6+10;
int n,d;
int x[N];
int cnt[N];
int f[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		int ans=0;
		for(int i=1;i<=n;i++){
			memset(f,0x3f3f3f3f,sizeof f);
			memset(cnt,0,sizeof cnt);
			f[i]=0;
			cnt[i]=1;
			for(int j=i;j<=n;j++){
				if(cnt[j]>2){
					continue;
				}
				if(cnt[j]==2){
					ans++;
				} 
				for(int k=1;k+j<=n;k++){
					if(x[j+k]>d+x[j]){
						break;
					}
					if(f[j]+1<f[j+k]){
						f[j+k]=f[j]+1;
						cnt[j+k]=cnt[j];
					}
					else if(f[j]+1==f[j+k]){
						cnt[j+k]+=cnt[j];
					}
				}
			}

		}
		cout<<ans<<endl;
	}
	return 0;
}

