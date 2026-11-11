#include<bits/stdc++.h>
using namespace std;
int a[100001];
int maxn=-1;
int n,m;
void dfs(int i,int g,int sum) {
	if(g==m) {		
		maxn=max(maxn,sum);
		return ;
	}
	if(i==n+1) {
		return ;
	}
	dfs(i+1,g+1,sum&a[i]);
	dfs(i+1,g,sum);
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long chus=1024*1024-1;
	if(m==1) {
		int maxx=-1;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
	} else if(m==2) {
		int maxx=-1;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
	} else if(m==n) {
		cin>>a[1];
		int sum=a[1];
		for(int i=2; i<=n; i++) {
			cin>>a[i];
			sum=sum&a[i];
		}
		cout<<sum;
	}else{
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		dfs(1,0,chus);
		cout<<maxn;
	}
	return 0;
}

