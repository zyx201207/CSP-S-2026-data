#include<bits/stdc++.h>
using namespace std;
void solve(){
	long long n,d;
	cin>>n>>d;
	vector<int> x(n, 0);
	for(int i = 1;i<=n;i++){
		cin>>x[i];
	}
	sort(x.begin()+1,x.end()+1);
	long long ans = 0;
	for(int i = 1;i<=n;i++){
		for(int j = i+1;j<=n;j++){
			if(x[j]-x[i] <= d) continue;
			if(j-i == 3){
				int p = i+1;
				int q = j-1;
				if(x[j]-x[q] <= d && x[q]-x[p] <= d && x[p]-x[i]) ans++;
			}
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
