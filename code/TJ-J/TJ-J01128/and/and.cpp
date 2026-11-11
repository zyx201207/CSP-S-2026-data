#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int u[n];
	for(int i=0;i<n;i++){
		cin>>u[i];
	}
	sort(u,u+n);
	int a=u[n-1];
	for(int i=n-1;i>=n-m;i--){
		a=a&u[i];
	}
	cout<<a;
	return 0;
} 
