#include <bits/stdc++.h>
using namespace std;
long long m,ans,a[2000010];
int n,c,l,t,ct,b[2000010];
inline void solve(const int &l,const int &r){
	if (r-l<3) return;
	ct=0;
	for (int i=l;i<r-2;i++)
		if (a[i+3]-a[i]>m&&a[i+3]-a[i]<m<<1&&
			a[i+2]-a[i]<=m&&a[i+3]-a[i+1]<=m)
				b[++ct]=i;
	for (int i=l;i<r;i++)
		for (int j=i+1;j<=r;j++){
			bool bo=false;
			for (int k=1;k<=ct;k++)
				if (i<=b[k]&&b[k]+3<=j){
					if (bo){
						bo=false;
						break;
					}
					bo=true;
				}
			if (bo) ++ans;
		}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>t;
	b[0]=-3;
	while (t--){
		ans=0;
		cin>>n>>m;
		for (int i=1;i<=n;i++) cin>>a[i];
		l=1;
		for (int i=1;i<n;i++)
			if (a[i+1]-a[i]>m){
				solve(l,i);
				l=i+1;
			}
		solve(l,n);
		cout<<ans<<'\n';
	}
	return 0;
}
/*
wo yao shang mi ho xing wei da shang miao
luogu: 792318
wo bu shi mao niang miao
*/
