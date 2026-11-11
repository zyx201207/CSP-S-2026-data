#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],d[500005],t;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) d[i]=d[i-1]+a[i];
	for(int i=1;i<=n;i++){
		if(d[i]+m>=a[i]*(n-i+1)){
			t=i;
			break;
		}
	}
	cout<<n-t+1;
	return 0;
}
