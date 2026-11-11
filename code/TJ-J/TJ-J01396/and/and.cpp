#include<bits/stdc++.h>
using namespace std;
//guodedaima
long long a[200005];
bool cmp(int a,int b){
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
	sort(a+1,a+n+1,cmp);
	long long ans=a[1];
	for(int i=2;i<=m;i++){
		(ans&=a[i]);
	}
	cout<<ans;
	return 0;
}