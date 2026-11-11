#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	int lasti=0,last=v[0],c=1,ans=1;
	for(int i=1;i<n;i++){
		m-=(v[i]-last)*(i-lasti);
		last=v[i];
		c++;
		while(m<0){
			m+=v[i]-v[lasti];
			lasti++;
			c--;
		}
		ans=max(ans,c);
	}
	cout<<ans;
	return 0;
}
