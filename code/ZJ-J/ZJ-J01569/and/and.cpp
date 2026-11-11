#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
const long long O=2e8;
int n,m;
int a[N];
int qans;
void dfs(int d,int x,int y){
	if(d>n){
		if(x==m){
			qans=max(qans,y);
		}
		return;
	}
	dfs(d+1,x,y);
	dfs(d+1,x+1,y&a[d]);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//	cout<<(5&2);
	cin>>n>>m;
	int o=(1<<30)-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		int ans=0;
		for(int i=1;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(n<=20){
		dfs(1,0,o);
		cout<<qans;
		return 0;
	}
	if((long long)n*m<=O){
		vector<vector<int>> f(n+1,vector<int>(m+1,0));
		f[0][0]=o;
		for(int i=1;i<=n;i++){
			f[i][0]=o;
			for(int j=1;j<=min(i,m);j++){
				f[i][j]=max(f[i-1][j],f[i-1][j-1]&a[i]);
//				cout<<f[i][j]<<" \n"[j==i];
			}
		}
		cout<<f[n][m];
		return 0;
	}
	bool A=1;
	for(int i=1;i<=n;i++){
		int x=a[i]+1;
		while(x>1&&x%2==0){
			x/=2;
		}
		if(x!=1){
			A=0;
			break;
		}
	}
	if(A){
		sort(a+1,a+n+1);
		int ans=o;
		cout<<a[n-m+1];
		return 0;
	}
	if(m==n-1){
		int mi=o,jm=1;
		int ans=o;
		for(int i=1;i<=n;i++){
			if(~a[i]<mi){
				mi=~a[i];
				jm=i;
			}
		}
		for(int i=1;i<=n;i++){
			if(i==jm) continue;
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	return 0;
}