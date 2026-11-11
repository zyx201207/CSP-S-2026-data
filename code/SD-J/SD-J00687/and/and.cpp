#include<bits/stdc++.h>
using namespace std;
int m,n;
long long a[200005];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	long long sum=a[1]&a[2];
	for(int i=3;i<=m;i++){
		sum&=a[i];
	}
	cout<<sum;
	return 0;
}
