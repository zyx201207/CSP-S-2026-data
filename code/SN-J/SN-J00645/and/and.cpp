//TYZ lizihan SN-J00645

#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m,a[200005];
vector<int>s1,s2;

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)s1.push_back(a[i]);
	for(int i=30;i>=0;i--){
		int t=s1.size();
		for(int j=0;j<t;j++){
			if((s1[j]>>i)&1)s2.push_back(s1[j]);
		}
		int tt=s2.size();
		if(tt>=m)swap(s1,s2);
		s2.clear();
	}
	int ans=s1[0];
	int tt=s1.size();
	for(int i=1;i<tt;i++)ans=(ans&s1[i]);
	cout<<ans;
	
	return 0;
}
