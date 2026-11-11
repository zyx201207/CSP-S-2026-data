#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	int n,d;
	cin>>n>>d;
	vector<int> a(n+5);
	bool Speacial_Tasks_A=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
		if(i>3&&a[i-1]-a[i-2]!=a[i-2]-a[i-3])	Speacial_Tasks_A=false;
	}
	if(Speacial_Tasks_A){
		cout<<(n+d-1)/(d+1)<<'\n';
		return ;
	}
	int cnt=0;
	for(int i=1;i<=n-3;i++){
		if(abs(a[i]-a[i+2])<=d&&abs(a[i+2]-a[i+3])&&abs(a[i]-a[i+1])<=d&&abs(a[i+1]-a[i+3]))
			cnt++;
	}
	cout<<cnt<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	int c,t;
	cin>>c>>t;
	while(t--)	solve();

	return 0;
}
