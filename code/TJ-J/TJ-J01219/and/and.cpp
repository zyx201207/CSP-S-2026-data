#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n],b[n],maxn=0;;
	for(int i=0;i<n;i++){
		cin>>a[i];
		maxn=max(a[i],maxn);
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
} 
