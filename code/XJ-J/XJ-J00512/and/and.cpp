#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and3.in","r",stdin);
	freopen("and.ans","w",stdout);
	int n,m,x=0;
	cin>>n>>m;
	long long s=(n+1)*n/2;
	int a[10005];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<s;i++){
		x=max(x,a[i]&a[i+1]);
}
	cout<<x;
	
	return 0;
	
}