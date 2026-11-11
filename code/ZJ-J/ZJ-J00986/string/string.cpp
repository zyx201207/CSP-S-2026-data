#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,num,ans;
char ch;
string s;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	²âÊÔµã 1-12 / 17-21  0-68pts
	cin>>t;
	while(t--) {
		cin>>num;
		cin.get();
		cin>>ch;
		for(int i=0; i<num; i++) {
			s+=ch;
		}
	}
	ll len=s.size();
	for(ll i=0; i<len/2; i++) {
		if(s[i]!=s[len-i-1]) {
			ans++;
			s[i]=s[len-i-1];
		}
	}
	cout<<ans;
	return 0;
}
