#include<bits/stdc++.h>
using namespace std;
#define int long long
void pl(){
	int n,ans=0,d;
	cin>>n>>d;
	vector<int>a(2e6+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(2*d<a[4]-a[1]){
		cout<<0;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(a[i]+d+d-(a[2]-a[1])<=a[n])ans++;
	}
	cout<<ans;
	return ;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t,c;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		pl();
		cout<<endl;
	}
	return 0;
}