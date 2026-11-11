#include<bits/stdc++.h>
using namespace std;
long long a[10000005],s[100000005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		s[i]=max(a[i-1],a[i]);
	}
	sort(s,s+n);
	cout<<s[n];
	return 0;
}
