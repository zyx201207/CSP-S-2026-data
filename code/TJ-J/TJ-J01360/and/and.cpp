#include<bits/stdc++.h>

using namespace std;
int a[300000],b[9000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	cout<<a[n/2+1];
	
	return 0;
	//It's~okay!
}
