#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long i=0,j,n,m,cnt=0,T,k,l,a[1000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	cout<<a[n-1];
	return 0;
}
