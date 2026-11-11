#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N];
long long m,n;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long s=a[n];
	for(int i=n-1;i>=n-m+1;i--){
		s=(s&a[i]);
	}
	cout<<s;
	return 0;
}
