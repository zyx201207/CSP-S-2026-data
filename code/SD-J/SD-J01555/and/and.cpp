#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(m==1) cout<<a[n];
	else if(m==2) cout<<a[n-1];
	else cout<<a[n-m+1];
	return 0;
}

