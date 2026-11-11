#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans;
pair<char,int> a[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].second>>a[i].first;
	int l=1,r=n;
	while(l<r){
		int c;
		if(a[l].second!=a[r].second) c=max(a[l].second,a[r].second)-min(a[l].second,a[r].second);
		else c=a[l].second;
		a[l].second-=c,a[r].second-=c;
		if(a[l].first!=a[r].first) ans+=c;
		if(a[l].second==0) l++;
		if(a[r].second==0) r--;
	}
	cout<<ans;
	return 0;
}

