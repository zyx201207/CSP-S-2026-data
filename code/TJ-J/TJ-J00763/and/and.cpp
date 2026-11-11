#include<bits/stdc++.h>
using namespace std;
int a[100001];
int b[100001];
int main(){
	
	int n,m;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
	//	return(a[i]%2&&a[i+1]%2);
		
		b[i]=a[i];
	}
	cout<<b[n];	
	fclose(stdin);
	fclose(stdout);
	return 0;
}; 
