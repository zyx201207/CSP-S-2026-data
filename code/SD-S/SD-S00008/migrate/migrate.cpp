#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=0x3f3f3f3f;
const int inff=0x3f3f3f3f3f3f3f3f;
const int N=1e6+5;
const int M=305;
const int mod=1e9+7;
pair<int,int> dp[5005];
int sum[5005],n,c,t,d,a[N];
bool check(int i,int mid){
	if(a[i]-a[mid]>d){
		return 0;
	}
	return 1;
}
void fast(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	fast();
	cin>>c>>t;
	if(c>=0&&c<=6){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=0;j<=n;j++){
					dp[j].first=dp[j].second=0;
					sum[j]=0;
				}
				dp[i]={0,1};
				sum[i]=1;
				int x=i;
				for(int j=i+1;j<=n;j++){
//					cout<<j<<endl;
					int l=i,r=j;
					while(l<r-1){
//						cout<<'a'<<' '<<l<<' '<<r<<endl;
						int mid=(l+r)>>1;
						if(check(j,mid)){
							r=mid;
						}
						else{
							l=mid;
						}
					}
					if(check(j,l)){
						r=l;
					}
//					cout<<r<<' ';
					if(r==j){
						dp[j]={0,0};
						x=j-1;
						continue;
					}
					if(dp[r].first+1!=dp[j-1].first){
						x=j-1;
					}
//					cout<<x<<'\n';
					dp[j]={dp[r].first+1,sum[x]-sum[r-1]};
					sum[j]=dp[j].second+sum[j-1];
					if(dp[j].second==2){
						ans++;
					}
				}
//				cout<<'\n';
//				for(int j=1;j<=n;j++){
//					cout<<dp[j].second<<' ';
//				}
//				cout<<'\n';
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
