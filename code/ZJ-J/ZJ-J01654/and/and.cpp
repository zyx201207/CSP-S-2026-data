#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	long long a[100005];
	cin>>n>>m;;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	sort(a+1,a+n+1,cmp);
	long long ans=a[1];
	for(int i=2;i<=m;i++){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}