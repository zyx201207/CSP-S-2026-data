#include<bits/stdc++.h>
#define ll long long

using namespace std;

int n;
string str1;
ll len=0LL,ans=0LL;

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--) {
		int anxi;
		char chri;
		cin>>anxi>>chri;
		len+=anxi;
		for(int i=1; i<=anxi; i++) {
			str1+=chri;
		}
	}
	//cout<<str1<<' '<<len<<'\n';
	for(ll i=0; i<(len/2); i++) {
		if(str1[i]!=str1[len-1-i]) {
			++ans;
		}
	}
	cout<<ans<<'\n';
	return 0;
}