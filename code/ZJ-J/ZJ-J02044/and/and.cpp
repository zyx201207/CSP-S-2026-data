#include<bits/stdc++.h>
using namespace std;
const int N=5e6;
long long a[N+10],b[N+10];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int pzt=0;
	pzt=a[n];
	for(int i=n-1;i>n-m;i--){
		pzt=pzt & a[i];

	}
	cout<<pzt;
	return 0;
}