#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	cout<<a[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
