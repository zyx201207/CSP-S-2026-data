#include<bits/stdc++.h>
using namespace std;
vector<pair<long long,char> > v;
long long n,a,cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char c;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		v.push_back({a,c});
	}
	for(int i=0;i<n/2;i++){
		if(v[i].second!=v[n-i-1].second) cnt+=max(v[i].first,v[n-i-1].first);
		else continue;
	}
	cout<<cnt;
	return 0;
}
