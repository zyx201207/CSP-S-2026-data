#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e7+10;
int n,ans,len,t,d;
int a[N];
char c[N],ch;
string s;
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>c[i];
		len+=a[i];
		while(a[i]>0) {
			s+=c[i];
			a[i]--;
		}
	}
	for(int i=1; i<=n; i++) {
		if(c[1]==c[i]) {
			t++;
		}
	}
	if(t==n) {
		cout<<0;
		return 0;
	}
	int x=1,y=len;
	while(x<y) {
		if(s[x]==s[y]) {
			continue;
		} else {
			ans++;
		}
		x++;
		y--;
	}
	cout<<ans<<endl;
	return 0;
}

