#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
long long a[maxn];
int n,d;
long long sum;
long long f[maxn];
long long cnt;
long long ans;
int di[maxn];
void dfs(int s,int x){
	if(s!=x){
		if(sum<f[s]){
			di[s]=1;
			f[s]=sum;
		}
		else if(sum==f[s]){
			di[s]++;
		}
	}
	for(int i=s+1;i<=n;i++){
		if(a[i]-a[s]<=d){
			sum+=(a[i]-a[s]);
			dfs(i,x);
			sum-=(a[i]-a[s]);
		}
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ans=0;
		for(int i=1;i<=n;i++){
			cnt=0;
			sum=0;
			memset(f,1e18,sizeof(f));
			memset(di,0,sizeof(di));
			dfs(i,i);
			for(int j=1;j<=n;j++){
				if(di[j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}