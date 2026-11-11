#include<bits/stdc++.h>
using namespace std;
long long a[2000010];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	long long x=a[1]&a[2];
	for(long long i=3;i<=m;i++){
		x=x&a[i];
	}
	cout<<x;
	return 0;
}
