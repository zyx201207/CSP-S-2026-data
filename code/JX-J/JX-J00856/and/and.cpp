#include<bits/stdc++.h>
using namespace std;
int a[1000000],da=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		if(a[i]>da)
		da=a[i];
	}
	cout<<da;
	return 0;
}
