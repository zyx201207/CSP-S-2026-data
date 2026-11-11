#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+9;
int a[N];
int mx;
int dp[N][N];
vector<int>v[N];
int n,m;
void dfs(int x,int l,int mid){
	dp[x][0]=1;
	for(auto i:v[x]){
		if(i==l)continue;
		dfs(i,x,mid);
		for(int j=1;j<=mid;j++){
			dp[x][j]+=dp[i][j-1];
		}
	}
}
bool check(int mid){
	for(int id=1;id<=n;id++){
		for(int i=1;i<=n;i++){
			for(int j=0;j<=mid;j++){
				dp[i][j]=0;
			}
		}
		dfs(id,0,mid);
		int sum=0;
		for(int j=0;j<=mid;j++){
			sum+=dp[1][j];
		}
		if(sum>=m){
//			cout<<id<<'\n';
			return 1;
		}
	}
	return 0;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int pangtouyukuangzhanshi;
	cin>>pangtouyukuangzhanshi;
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			v[i].clear();
		}
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		int m1=m;
		int mn=1e18;
		for(int i=1;i<=m1;i++){
			m=m1-i;
			int l=0,r=n;
			while(l+1<r){
				int mid=(l+r)>>1;
				if(check(mid-1)){
					r=mid;
				}else{
					l=mid;
				}
			}
			int cur=r;
			m=i;
			l=0,r=n;
			while(l+1<r){
				int mid=(l+r)>>1;
				if(check(mid-1)){
					r=mid;
				}else{
					l=mid;
				}
			}
			mn=min(mn,max(cur,r));
		}
		cout<<mn<<'\n';
	}
	return 0;
} 
