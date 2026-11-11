#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	cin.tie(0),cout.tie(0);
	int n,m,a[1000],k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		k=a[i];
		for(int j=1;j<=n;j++){
			if(k==a[j]){
				for(int k=1;k<=i-1;k++){
					a[k]==0;
				}
			}
		}
		
	}
	return 0;
} 
