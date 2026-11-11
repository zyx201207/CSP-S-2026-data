#include<bits/stdc++.h>
using namespace std;
int m,n,a[200100],maxx=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	} 
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
