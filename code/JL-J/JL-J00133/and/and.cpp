#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a[1000005],num,b,n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	b=n;
	num=a[b];
	for(int i=b;i>b-m;i--){
		num=(num & a[i]);
	}
	cout<<num;
	return 0;
}
