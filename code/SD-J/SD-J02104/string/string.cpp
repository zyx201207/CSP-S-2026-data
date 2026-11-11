#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=222222;
string s;
int n,a[N],sa[N];
char c[N];
int ans;
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sa[i]=a[i]+sa[i-1];
	}
	int lastl=1,lastr=n;
	char lc,rc;
	for(int l=1,r=sa[n];l<=r;l++,r--){
		if(l>sa[lastl]){
			lastl++;
		}
		if(r<=sa[lastr-1]){
			lastr--;
		}
		if(c[lastl]!=c[lastr]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
