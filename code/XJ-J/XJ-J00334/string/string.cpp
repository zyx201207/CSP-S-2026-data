#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+9;
const int M=1e9;
int n,a[N],maxx=-0x3f3f3f3f,sum=0;
char c[N];
string s;
signed main() {
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i],sum+=a[i];
	if(maxx<=500) {
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++) s+=c[i];
		}
		int cnt=0;
		if(sum%2==0) {
			for(int i=0;i<(sum-1)/2;i++) {
				if(s[i]!=s[sum-1-i]) cnt++;
			}	
		}
		else {
			for(int i=0;i<(sum+1)/2;i++) {
				if(s[i]!=s[sum-1-i]) cnt++;
			}
		}
		cout<<cnt;
	}
	return 0;
} 
