#include<bits/stdc++.h>
using namespace std;
long long n,m,b;
int a[200005];
int main(){
	freopen("and4.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(a[n-m+1]==a[n]){
		cout<<a[n-m];
		return 0;
	}
	if(a[n-m]==a[n-1]){
		cout<<a[n-m];
		return 0;
	}
	int b=a[n];
	for(int i=n;i>=m;i--){
		
		b=b&a[i];
	}
	cout<<b;
	return 0;
}
