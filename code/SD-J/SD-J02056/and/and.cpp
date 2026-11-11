#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	long long ans=a[1];
	for(long long i=1;i<=m;i++){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}
