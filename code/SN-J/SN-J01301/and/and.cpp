#include<bits/stdc++.h>
using namespace std;
//É¾³ýfreopen×¢ÊÍ!!!
//²âÊÔÊä³öÉ¾³ý£¡£¡
long long m,n;
long long a[200005];
long long ans;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	ans=a[1];
	for(int i=2;i<=m;i++){
		ans=ans&a[i];
	}
	cout<<ans; 
	return 0;
}
