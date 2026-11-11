#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long m,n,a[20005],maxx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(a[i],a[i-1]); 
	}
	cout<<maxx; 
	return 0;
} 
