#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
long long a[N+5];
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	long long ans=a[n];
	for(int i=n-1;i>n-m;i--){
		ans=ans&a[i];
	}
	cout<<ans;
} 
