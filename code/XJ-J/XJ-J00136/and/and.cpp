#include<bits/stdc++.h>
using namespace std;
#define ll long long
long long int n,a[200020],maxn,sum[200020];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	for(ll int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	maxn=a[n]&a[n-1];
	cout<<maxn;
	return 0;
}
