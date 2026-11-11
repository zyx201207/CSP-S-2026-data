#include<bits/stdc++.h>
using namespace std;
char c[1000000];
int ans=0;
int t=1;
int n,m;
char c1;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	cin>>n;
	cin>>m;
	cin>>c1;
	c[0]=c1;
	for(int j=0; j<m; j++) {
		s+=c1;
	}
	for(int i=1; i<n; i++) {
		cin>>m;
		cin>>c1;
		if(c[i-1]!=c1)t=0;
		for(int j=0; j<m; j++) {
			s+=c1;
		}
	}
	if(t==1){
		cout<<0;
		return 0;
	}
	int l=0,r=s.size()-1;
	while(l<r) {
		if(s[l]!=s[r]) {
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}