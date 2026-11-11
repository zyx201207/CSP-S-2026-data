#include<bits/stdc++.h>
#define int long long
#define I_want_to_AK_csp return
using namespace std;

int n;
const int N=200005;
int num[N];
char c[N];

signed main() {
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>num[i]>>c[i];
	}
	
	string s1,s2;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=num[i]; j++) {
			s1+=c[i];
		}
	}
	for(int i=s1.size()-1; i>=0; i--) {
		s2+=s1[i];
	}
	
	int cnt=0;
	for(int i=0; i<s1.size(); i++) {
		if(s1[i]==s2[i]) {
			cnt++;
		}
	}
	
	cout<<(s1.size()-cnt)/2;
	
	I_want_to_AK_csp 0;
}

