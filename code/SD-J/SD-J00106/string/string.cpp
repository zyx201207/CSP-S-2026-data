#include <bits/stdc++.h>
using namespace std;
const int nm=300010;
char f[nm]; 
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vector<int> a(n+1); 
	vector<char> s(n+1);
	int g;
	for(int i=1;i<=n;i++) {
		cin>>a[i]>>s[i];
		if(i==1) {
			g=a[i];
		}
		else {
			g=__gcd(g,a[i]);
		}
	}
	int ggg=0;
	for(int i=1;i<=n;i++) {
		for(int j=ggg+1;j<=ggg+(a[i]/g);j++) {
			f[j]=s[i];
		}
		ggg+=(a[i]/g);
	}
	long long ans=0;
	for(int i=1;i<=(ggg+1)/2;i++) {
		if(f[i]!=f[ggg+1-i]) {
			ans+=g;
		}
	}
	cout<<ans;
	return 0;
}
