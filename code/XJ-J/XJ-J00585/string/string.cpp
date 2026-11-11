#include<bits/stdc++.h>
using namespace std;
long long n;
string s;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cin>>n;
	long long idx=1;
	for(int i=1;i<=n;i++) {
		long long x;
		char a;
		cin>>x>>a;
		for(int i=1;i<=x;i++) {
			s[idx]=a;
			idx++;
		}
	}
	long long ans=0,l=1,r=idx-1;
	while(l<r) {
		if(s[l]!=s[r]) ans++;
		l++;
		r--;
	}
	cout<<ans;
	return 0;
} 
