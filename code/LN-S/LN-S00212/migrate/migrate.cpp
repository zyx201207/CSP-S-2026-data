#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,d,a[N],l[3][N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		memset(l,0,sizeof l);
		for(int i=1;i<=n;++i)cin>>a[i];
		if(n==4&&a[n]-a[2]<=d&&a[n-1]-a[1]<=d&&a[n]-a[1]>d){
			cout<<1<<'\n';
			continue;
		}
		for(int i=2;i<n;++i){
			int flag=0;
			for(int j=1;j<=n;++j){
				if(i==j){
					flag=1;
					continue;
				}
				if(abs(a[i]-a[j])<=d){
					l[flag][j]++;
				}
			}
		}
		int u=0,v=0;
		for(int i=1;i<=n;++i){
			if(l[0][i]==2)u++;
			if(l[1][i]==2)v++;
		}
		cout<<max(u,v)<<'\n';
	}
	return 0;
}
