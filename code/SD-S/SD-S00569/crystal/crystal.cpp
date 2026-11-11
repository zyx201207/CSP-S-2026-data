#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],pre[500005],xd[500005],ma=1,mas;
void dfs(int x,int y) {
	if(x>n ) {
		for(int i=0; i<mas+m; i++) {
			ma=max(ma,xd[i]);
		}
		return ;

	}
	for(int i=0; i<y; i++) {
		xd[x]--;
		xd[x+i]++;
		dfs(x+1,y-i);
		xd[x]++;
		xd[x+i]--;
	}

}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		xd[a[i]]++;
		mas=max(mas,a[i]);
	}
	dfs(0,m);
	cout<<ma;
	return 0;
}
