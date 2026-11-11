#include <bits/stdc++.h>
using namespace std;
const int N=5005;
int c,t,n,d,x[N],ans,sum=1e9,num;
void dfs(int a,int ed,int step) {
	if (a==ed) {
		if (sum>step) sum=step,num=1;
		else if (sum==step) num++;
		return;
	}
	for (int i=a+1;i<=ed&&x[i]-x[a]<=d;i++) {
		dfs(i,ed,step+1);
	}
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >>c>>t;
	while (t--) {
		cin >>n>>d;
		for (int i=1;i<=n;i++) cin >>x[i];
		ans=0;
		for (int i=1;i<=n;i++) {
			for (int j=i+3;j<=n;j++) {
				sum=1e9,num=0;
				dfs(i,j,0);
				ans+=num==2;
			}
		}
		cout <<ans<<"\n";
	}
	return 0;
}

