#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[2000050];
int dp[5050][5050];
int f[5050][5050];
int lt[5050];
int s[5050][5050];
int dp2[2000100];
int f2[2000100];
int lt2[2000100];
int s2[2000100];

void solve(int T){
	while(T--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			dp2[i]=0;
			f2[i]=1;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
			int l=1,r=i,ans=i;
			while(l<=r){
				int mid=(l+r)>>1;
				if(a[mid]<a[i]-d){
					l=mid+1;
				}else{
					r=mid-1;
					ans=mid;
				}
			}
			lt[i]=ans;
		}
		int l=1;
			s2[l]=f2[l];
			for(int len=2;l+len-1<=n;len++){
				int r=l+len-1;
				if(lt2[r]==r||dp2[lt[r]]==1e18){
					dp2[r]=1e18;
					f2[r]=0;
				}else{
					int el=lt2[r],er=r-1,ans=lt2[r];
					while(el<=er){
						int mid=(el+er)>>1;
						if(dp2[mid]>dp2[lt[r]]){
							er=mid-1;
						}else{
							el=mid+1;
							ans=mid;
						}
					}
					
					//if(l==1&&r==4&&T==0)cout<<dp[1][3]<<'t';
					dp2[r]=dp2[lt[r]]+1;
					f2[r]=s2[ans]-s2[lt[r]-1];
				}s2[r]=s2[r-1]+f2[r];//cout<<f[l][r]<<' ';
			}//cout<<'\n';
		
		int ans=0;
		for(int i=1;i<=n;i++){
			if(f2[i]==2){
				ans=n-i+1;
				break;
			}
		}cout<<ans<<'\n';
	}
}
signed main(){
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	if(c==11||c==12){
		solve(T);
		return 0;
	}
	while(T--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			dp[i][i]=0;
			f[i][i]=1;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
			int l=1,r=i,ans=i;
			while(l<=r){
				int mid=(l+r)>>1;
				if(a[mid]<a[i]-d){
					l=mid+1;
				}else{
					r=mid-1;
					ans=mid;
				}
			}
			lt[i]=ans;
		}
		for(int l=1;l<=n;l++){
			s[l][l]=f[l][l];
			for(int len=2;l+len-1<=n;len++){
				int r=l+len-1;
				if(lt[r]==r||dp[l][lt[r]]==1e18){
					dp[l][r]=1e18;
					f[l][r]=0;
				}else{
					int el=lt[r],er=r-1,ans=lt[r];
					while(el<=er){
						int mid=(el+er)>>1;
						if(dp[l][mid]>dp[l][lt[r]]){
							er=mid-1;
						}else{
							el=mid+1;
							ans=mid;
						}
					}
					
					//if(l==1&&r==4&&T==0)cout<<dp[1][3]<<'t';
					dp[l][r]=dp[l][lt[r]]+1;
					f[l][r]=s[l][ans]-s[l][lt[r]-1];
				}s[l][r]=s[l][r-1]+f[l][r];//cout<<f[l][r]<<' ';
			}//cout<<'\n';
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(f[i][j]==2){
					ans++;
					//cout<<i<<' '<<j<<'\n';
				}
				//cout<<f[i][j]<<' ';
			}//cout<<'\n';
		}cout<<ans<<'\n';
	}
	return 0;
}
