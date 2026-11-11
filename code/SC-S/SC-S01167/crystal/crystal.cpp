#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a.begin(),a.end());
	int ans=0;
	for(int i=1;i<=n;i++){
		int aa=0,f=0;
		for(int j=1;j<=i;j++){
			f+=a[i]-a[j];
			if(f<=m) aa++;
		}
		ans=max(ans,aa);
	}
	cout<<ans;
	return 0;
} 


