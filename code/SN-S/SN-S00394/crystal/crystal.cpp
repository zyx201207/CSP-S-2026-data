#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000001],b[1000001];
int s[1000001];
int s2[1000001];
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n-1; i>=1; i--) {
		s[i]=s[i+1]+abs(a[i]-a[n]);
//		cout<<a[i+1]-a[i]<<' ';
//		cout<<s[i+1]<<' ';
//		cout<<endl;
	}
	for(int i=n-1; i; i--)s2[i]=s2[i+1]+s[i];
	int ans=0;
	for(int i=2; i<=n; i++) {
		int L=0,R=i;
		while(L+1<R){
			int M=(L+R)/2;
			if(s[M]<(m+s2[i]))R=M;
			else L=m;
		}
		ans=max(ans,i-L);
	}
	cout<<ans<<endl;
//	for(int i=1; i<n; i++)cout<<s[i]<<' ';
//	cout<<endl;
//	for(int i=2; i<=n; i++)cout<<s2[i]<<' ';
}
