#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	int k=1;
	cin>>n>>m;
	int a[99999];
	int b[99999];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<+n;i++){
		for(int j=1;j<=n;j++){
			b[k]=a[i]&&a[j];
			k++;
		}
	}
	sort(b+1,b+k+1);
	reverse(b+1,b+k+1);
	cout<<b[1];
	return 0;
} 
