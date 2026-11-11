#include<bits/stdc++.h>
using namespace std;
long long n,m;
string s;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++) {
		long long t;
		char a;
		cin>>t>>a;
		m+=t;
		for(int j=1; j<=t; j++) {
			s+=a;
		}
	}
	int mid=ceil(m*1.0/2),l,cnt=0,ans=0;
	if(mid*2-1==m) {
		for(int i=mid+1; i<=m; i++) {
			if(s[l]!=s[i]) {
				cnt++;
			}
		}
		l=mid;
		ans=cnt;
		cnt=0;
		for(int i=1; i<mid; i++) {
			if(s[i]!=s[l]) {
				cnt++;
				l++;
			}
		}
		cout<<min(ans,cnt);
		return 0;
	} else {
		for(int i=mid+2; i<=m; i++) {
			if(s[l]!=s[i]) {
				cnt++;
			}
		}
		l=mid;
		ans=cnt;
		cnt=0;
		for(int i=1; i<=mid-2; i++) {
			if(s[i]!=s[l]) {
				cnt++;
				l++;
			}
		}
		if(s[mid]==s[mid+1]){
			cout<<min(ans,cnt);
		} else {
			cout<<min(ans,cnt)+1;
		}		
		return 0;
	}
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/