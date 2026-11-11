#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	long long n,m;
	cin>>n>>m;
	long long a[n+10];
	for(long long i=0;i<n;i++){
		cin>>a[i];
	} 
	sort(a,a+n);
	cout<<a[m-1];
	return 0;
}
