#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500010],s[500010];
int n,m;
bool check(int x){
	vector<int>v;
	for(int i=1;i<=n;i++){
		if(a[i]>x)break;
		v.push_back(x-a[i]);
	}
	sort(v.begin(),v.end());
	
}
signed main(){
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i]; 
		//cout<<s[i]<<' ';
	}
	int r=1,ans=1;
	for(int l=1;l<=n;l++){
		while(r<n&&(r-l+1)*a[r]-(s[r]-s[l-1])<=m)r++;
		//cout<<l<<':'<<r<<'\n';
		ans=max(ans,(r-((r-l+1)*a[r]-(s[r]-s[l-1])>m)-l+1));
	}cout<<ans;
	return 0;
}
