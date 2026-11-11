#include<bits/stdc++.h>
#define int long long
using namespace std;
string x[200005];
bool is[200005];
int bigm=0;
string to2(int n) {
	string t="";
	string to="";
	int m=0;
	while(n!=0) {
		if(n%2==1) {
			t+='1';
		} else {
			t+='0';
		}
		n/=2;
		m++;
	}
	for(int i=m-1; i>=0; i--) {
		to+=t[i];
	}
	bigm=max(m,bigm);
	return to;
}
int to10(int n) {
	int t=1;
	for(int i=1; i<=n; i++) {
		t*=2;
	}
	return t;
}
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		int t;
		cin>>t;
		x[i]=to2(t);
	}
	for(int i=1; i<=n; i++) {
		if(x[i].length()<bigm) {
			string to="";
			for(int j=1; j<=bigm-x[i].length(); j++) {
				to+='0';
			}
			to+=x[i];
			x[i]=to;
		}
	}
	int ans=0;
	for(int i=0; i<bigm; i++) {
		int s=0;
		for(int j=1; j<=n; j++) {
			if(x[j][i]=='1'&&!is[j]) {
				s++;
			}
		}
		if(s<m) {
			continue;
		}
		for(int j=1; j<=n; j++) {
			if(x[j][i]=='0') {
				is[j]=1;
			}
		}
		ans+=to10(bigm-i-1);
	}
	cout<<ans;
	return 0;
}

