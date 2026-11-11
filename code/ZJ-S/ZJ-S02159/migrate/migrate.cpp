#include<bits/stdc++.h>
using namespace std;
int C;
long long a[2000010];
int c[2000010];
int dis[2000010];
int num[2000010];
void solve(){
	int n;
	long long d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
//	cout<<n<<'\n';
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			c[j]=0;
			num[j]=0;
			dis[j]=0;
		}
		int head=i;
		c[0]=1,dis[i]=0;
		num[i]=1;
		for(int j=i+1;j<=n;j++){
			while(head<j&&a[j]-a[head]>d){
				c[dis[head]]-=num[head];
				head++;
			}
//			cout<<head<<' '<<j<<'\n';
			if(head==j){
				break;
			}
			dis[j]=dis[head]+1;
			num[j]=c[dis[head]];
			c[dis[j]]+=num[j];
			if(num[j]==2){
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int t;
	cin>>C>>t;
	while(t--){
		solve();
	}
	return 0;
}