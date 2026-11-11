#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[510000],lz,l=1,S,q[510000];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)q[i]=q[i-1]+a[i];
	for(int i=1;i<=n;i++){
		while(a[i]*(i-l+1)-(q[i]-q[l-1])>m)l++;
		S=max(S,i-l+1);
	}
	cout<<S;
	return 0;
}
