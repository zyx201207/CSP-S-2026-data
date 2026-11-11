#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+11;
int T,dot,n,d,x[N],f[5001][5001],gs[5001][5001];
int one(int x){
	int cnt=0;
	while(x){
		cnt+=x&1;
		x>>=1;
	}
	return cnt;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>dot>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=2e18,gs[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++)cin>>x[i];
		sort(x+1,x+n+1);
		if(dot>=3){
			int ans=0;
			for(int i=1;i<=n;i++)f[i][i]=1;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(abs(x[j]-x[i])<=d){
						f[i][j]=2;
					}
				}
			}
			for(int len=3;len<=n;len++){
				for(int l=1;l+len-1<=n;l++){
					int r=l+len-1;
					for(int k=l+1;k<r;k++){
						f[l][r]=min(f[l][r],f[l][k]+f[k][r]-1);
					}
					int cnt=0;
					for(int k=l;k<=r;k++){
						if(f[l][k]+f[k][r]-1==f[l][r])cnt++;
					}
					if(cnt==1+f[l][r]){
						ans++;
						//cout<<'{'<<l<<','<<r<<"}\n";
					}
				}
			}
			cout<<ans<<'\n';
			continue;
		}
		for(int i=1;i<(1<<n);i++){
			int l=n+1,r=0;
			vector<int>pl;
			for(int j=1;j<=n;j++){
				if(((i>>(j-1))&1)==0)continue;
				l=min(j,l),r=max(j,r);
				pl.push_back(j);
			}
			bool flag=true;
			for(int i=1;i<(int)pl.size();i++){
				if(abs(x[pl[i]]-x[pl[i-1]])>d){
					flag=false;
					break;
				}
			}
			if(!flag)continue;
			if(one(i)<f[l][r]){
				gs[l][r]=1;
				f[l][r]=one(i);
			}else if(one(i)==f[l][r])gs[l][r]++;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(gs[i][j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}