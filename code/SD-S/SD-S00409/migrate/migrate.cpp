//17:15  1~2  8pts
/*#include <iostream>
using namespace std;
const long long N=510000;
long long c,t;
long long n,d;
long long a[N];
long long b[N];
long long cnt;
void dfs(long long k,long long ss,long long step,long long tt){
	if(k==ss && step==tt){
		cnt++;
		return;
	}
	if(cnt>2){
		return;
	}
	if(step>tt){
		return;
	}
	for(long long i=k+1;a[k]+d>=a[i] && i<=ss;++i){
		dfs(i,ss,step+1,tt);
	}
	return;
}
bool check(long long l,long long r){
	cnt=0;
	long long t=0;
	for(long long i=l;i<r;){
		b[t+1]=i;
		long long ii=i+1;
		while(a[ii]-a[i]<=d && ii<=r){
			++ii;
		}
		--ii;
		if(i==ii){
			return 0;
		}
		i=ii;
		++t;
	}
	dfs(l,r,0,t);
	return cnt==2;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long ans=0;
		cin>>n>>d;
		for(long long i=1;i<=n;++i){
			cin>>a[i];
		}
		for(long long i=1;i<=n;++i){
			for(long long j=i+1;j<=n;++j){
				ans+=check(i,j);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}*/

#include <iostream>
#include <cstring>
using namespace std;
const long long N=5100;
long long c,tt;
long long n,d;
long long a[N];
long long dp[N][N];
long long t[N][N];
long long ans;
int f(int l,int r){
	long long step=0;
	long long now=l;
	while(now!=r){
		++step;
		int p=now+1;
		while(a[now]+d>=a[p]){
			++p;
		}
		if(a[now]+d<a[p]){
			--p;
		}
		if(p==now){
			return 0;
		}
		if(p>=r){
			return step;
		}
		now=p;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>tt;
	while(tt--){
		ans=0;
		memset(dp,0,sizeof(dp));
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				t[i][j]=f(i,j);
				if(t[i][j]){
					dp[i][j]=1;
				}
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				for(int k=i+1;k<j;++k){
					if(t[i][k]+t[k][j]==t[i][j]){
						dp[i][j]+=dp[i][k]*dp[k][j];
					}
				}
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				if(t[i][j]){
					dp[i][j]--;
				}
				//cout<<dp[i][j]<<" ";
				ans+=bool(dp[i][j]==2);
			}
			//cout<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
