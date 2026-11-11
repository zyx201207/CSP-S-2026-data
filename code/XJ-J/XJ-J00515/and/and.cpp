#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,b=0;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;i++){
			b=max(b,a[i]^a[j]);		
		}
	}
	cout<<b;
	fclose(stdin);
	fclose(stdout);
	return 0;
}