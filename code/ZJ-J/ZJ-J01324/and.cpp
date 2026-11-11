#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a[1000020],n,s;
	cin>>n>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<a[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
