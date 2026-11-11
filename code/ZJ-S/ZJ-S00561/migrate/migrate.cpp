#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T;
int n,d;
int a[2000005];
void input(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
}
void run1(){
	int x=d/(a[2]-a[1]);
	if(x<=1||n<=2*x-1){
		cout<<0<<'\n';
		return;
	}
	cout<<n-2*x+1<<'\n';
}
int dis[5005][5005],cnt[5005][5005];
void run2(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e18+7;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(abs(a[i]-a[j])<=d)dis[i][j]=1;
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k)continue;
			for(int j=1;j<=n;j++){
				if(j==k||j==i)continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(k==i)continue;
			for(int j=1;j<=n;j++){
				if(j==i||k==j)continue;
				if(dis[i][j]==dis[i][k]+dis[k][j])cnt[i][j]++;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(cnt[i][j]==2)ans++;
		}
	}
	cout<<ans<<'\n';
}
void solve(){
	input();
	if(c<=10)run2();
	else if(11<=c&&c<=12){
		run1();
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--)solve();
	return 0;
}
/*
shou xian,N<=300 ke yi DP,xian pao floyd,zai dp[i][j] biao shi zui duan lu jing shu liang,O(sum(n^3)).
SPTA:
she X=[d/dis],dis=x2-x1,ze (j-i)==kX-1(X>1&&k>=1) jiu shi dui de. 
dui yu j-i=a,he fa fang an shu wei n-a
X<=1:0
else (n-(2X-1)+n-[(n+1)/X]X-1)*[(n+1)/X]/2;
1 2X
X+1 X

48pts
*/
