#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6+5 ;
int ans,c,T,n,d,f[N],cnt[N],p[N],pos,sum[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++)cin>>p[i];
		
		for(int st=1;st<=n;st++){
			
			for(int i=0;i<=n;i++)f[i]=1e9,cnt[i]=0,sum[i]=0;
			pos=st;
			f[pos]=0;
			cnt[0]=1;
			sum[pos]=1;
			
			for(int i=st+1;i<=n;i++){
				while((pos<=i)&&((p[i] - p[pos])>d)){
					cnt[f[pos]]-=sum[pos];
					pos++;
				}
				if(pos>=i)break;
				f[i]=f[pos]+1;
				sum[i]=cnt[f[pos]];
				if(sum[i]==2)ans++;
				cnt[f[i]]+=sum[i];
			}
		}
		
		cout<<ans<<'\n';
	}
	return 0;
}