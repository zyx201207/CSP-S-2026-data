#include<bits/stdc++.h>
using namespace std;

const long long N=200000010;
long long a[N];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int num=n*(n-1)/2;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<a[n];
	return 0;
}
