#include<bits/stdc++.h>
using namespace std;

int c,t,i,j,n,d;
int a[2*1000005];

int dfs(int x,int y,int num) {
	int minn,js=0;
	if(js==2) return true;
	if(x==y) js++;
	minn=min(minn,num);
	for(j=i; j<=n; j++) {
		if(a[i+1]-x<=d) {
			num+=1;
			dfs(a[i+1],y,num);
		} else break;
	}
	return false;
}

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		int ans=0;
		cin>>n>>d;
		for(i=1; i<=n; i++) {
			cin>>a[i];
		}
		for(i=1; i<=n; i++) {
			if(dfs(a[i],0,0)) {
				ans++;
			}
		}

		cout<<ans;
	}
	return 0;
}
