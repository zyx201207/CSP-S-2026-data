#include<bits/stdc++.h>
using namespace std;
int a[200010];
int b[200010];
int c[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
	}
	for(int j=n;j>=1;j--){
		for(int k=j;k>=1;k--){
			if(a[k]>=a[k-1]){
				b[k]=a[k];
				a[k]=a[k-1];
				a[k-1]=b[k];
			}
			else{
				break;
			}	
		}
	}
		
		
	
	cout<<a[m-1];
	return 0;
}
