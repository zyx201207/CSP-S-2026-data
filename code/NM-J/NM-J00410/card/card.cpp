#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,m; 
	cin>>n,m;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a[10000000000];
	int c[1000000000];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
		c[i]=a[i];
		
	}
	for(int i=1;i<=n;i++){
		int q=1;
		if(c[q]==a[i]){
			a[10000000000]=a[n];
		}
		else{
			q++;
		}
		
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]; 
	}
	return 0;
}