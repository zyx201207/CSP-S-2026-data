#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=2e5+5;
int a[N];
int ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>=m;i++){
		int s=i;
		for(int j=n-1;j>n-m;j++)s=(s&a[j]);
		ans=max(ans,s);
	}
	cout<<ans;
	return 0;
}
