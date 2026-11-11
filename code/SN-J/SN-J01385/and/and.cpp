#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[200005],b[200005];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int maxx=-1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			b[i]=a[j]&&a[j+1];
		}
		if(b[i]>maxx) maxx=a[i];
	}
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
