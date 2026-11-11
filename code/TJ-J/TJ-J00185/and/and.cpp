#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+5;
int m;
long long n;
long long a[N];
int main(){
	freopen("and.in", "r", stdin);
	freopen("ans.out", "w", stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1, a+n+1);
	int ans=a[n];
	for(int i=n-1;i>n-m;i--){
		ans &= a[i];
	}
	cout<<ans;
	return 0;
}
