#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	long long n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	int mx=a[1];
	for(int i=2;i<=k;i++){
		mx=(mx&a[i]);
	}
	cout<<mx;
	
	return 0;
}