#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long a[n+5];
	long long b;
	for(int i=0;i<n-1;i++){
		cin>>a[i];
	}
	cin>>b;
	cout<<b;
	return 0;
}