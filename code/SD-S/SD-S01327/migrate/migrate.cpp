#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 2000001
int c,t,ans=0,n,d,x[N],ans2[N],sum=0;
bool check=1,check1=1,check2=1;
void dfs(int s,int e,int d1){
	for(int i=s+1;i<=e&&x[i]-x[s]<=d1;i++){
//		cout<<s<<' '<<ans2[s]+1<<' '<<i<<'\n';
		if(i==e&&ans2[i]>ans2[s]+1){
			ans2[e]=ans2[s]+1;
			sum=1;
			return;
		}
		else if(i==e&&ans2[i]==ans2[s]+1)sum++;
		else if(i==e){
			check=0;
			return;
		}
		ans2[i]=ans2[s]+1;
		dfs(i,e,d);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		int cnt=0,maxn=-1;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i>=3&&x[i]-x[i-1]!=x[i-1]-x[i-2])check1=0;
		}
//		for(int i=1;i<=n;i++){
//			if(x[i]-x[1]<=d&&x[n]-x[i]<=d){
//				maxn=i;break;
//			}
//		}
//		if(maxn!=-1){
//			
//		}
		if(check1){
			int cha=x[n]-x[n-1];
			if(d<cha*2){
				cout<<0<<'\n';continue;
			}
			else {
				int maxil=d/cha;
				cout<<max(n-2*maxil+1,0LL)<<'\n';
				continue;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				check=1;
				memset(ans2,0x7f,sizeof ans2);
				ans2[i]=0;
				dfs(i,j,d);
				cnt=cnt+(sum==2);
				sum=0;
			}
		}
		cout<<cnt<<'\n';
	}
//	dfs(1,4,2);
//	cout<<sum;
	return 0;
} 



