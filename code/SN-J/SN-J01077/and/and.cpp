#include<bits/stdc++.h>
using namespace std;
int a[100000009];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.in","w",,stdout); 
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i]; 
	}
	for(int i=0;i<n;i++){
		if(a[i]!=i-1){
			break;
		}
		int p=a[i];
		while(n!=0){
			a[i]=a[i]%2+p/2;
			p/=2;
		}
		cout<<p;
	}
	return 0;
} 
