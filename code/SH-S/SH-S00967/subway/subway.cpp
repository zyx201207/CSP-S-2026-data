#include <bits/stdc++.h>
using namespace std;

const int maxn=500,maxm=500010;
int c,n,m,d,q;
int w[maxm];
int mnt[maxn];
int x,y,ans;
int sub[maxm];
/*void dfs(int line,int pos) {
	if (pos==y) {
		time+=w[y];
		ans=max(ans,time);
		return;
	}
	dfs(line,pos+1);
	
}*/
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) {
		cin >>w[i];
	}
	for (int i=1;i<=n;i++) {
		cin >>mnt[i];
		for (int j=1;j<=mnt[i];j++) {
			int tmp1,tmp2;
			cin >>tmp1>>tmp2;
			sub[tmp1]=tmp2;
		}
	}
	while (q--) {
		cin >>x>>y;
		cout <<w[x]+sub[x]+w[y]+sub[y]<<endl;
	}
	return 0;
}

