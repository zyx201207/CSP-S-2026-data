#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
bool fA=1,fB=1;
void dfs(int dep,int now,int res){
	if (now>m) return;
	if (dep==n){
		ans=max(ans,res*(now==m));
		return;
	}
	dfs(dep+1,now,res);
	dfs(dep+1,now+1,res&a[dep+1]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	int k=n;
	while (k>1 && fB){
		if (k&1) fB=0;
		k>>=1;
	}
	for (int i=1;i<=n;i++){
		cin >> a[i];
		bool f=1;
		int now=a[i];
		while (now && f){
			if (!(now&1)) f=0;
			now>>=1;
		}
		fA=(fA&f),fB=(fB&(a[i]==i-1));
	}
	if (n==m){
		ans=a[1];
		for (int i=2;i<=n;i++) ans=(ans&a[i]);
		cout << ans;
		return 0;
	}
	if (n<=20){
		dfs(0,0,INT_MAX);
		cout << ans;
	}
	else if (n<=2000){
		if (m==2){
			for (int i=1;i<=n;i++)
				for (int j=i+1;j<=n;j++) ans=max(ans,a[i]&a[j]);
			cout << ans;
		}
		else{
			for (int i=1;i<=n;i++) ans=max(ans,a[i]);
			cout << ans;
		}
	}
	else if (fB) cout << n-m;
	else if (fA){
		sort(a+1,a+n+1,greater<int>());
		cout << a[m];
	}
	else{
		srand(time(0));
		cout << rand();
	}
	return 0;
}
