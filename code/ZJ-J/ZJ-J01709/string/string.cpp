#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	vector<pair<long long,char> > a(n+1);
	long long l=0;
	for(int i=1;i<=n;i++) {
		cin>>a[i].first>>a[i].second;
		l+=a[i].first;
	}
	int hd=1,tl=n;
	long long cnt=0;
	while(hd<tl) {
		int mn=min(a[hd].first,a[tl].first);
		if(a[hd].second!=a[tl].second) cnt+=mn;
		a[hd].first-=mn;
		a[tl].first-=mn;
		if(a[hd].first==0) hd++;
		if(a[tl].first==0) tl--;
	}
	cout<<cnt<<"\n";
	return 0;
}
	