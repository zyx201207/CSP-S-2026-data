#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n,a[100001],r=0;
		for(int j=i-1;i<=n;i++){
			for(int f=2;f<=n;f++){
				if(a[j]==a[f]){
					for(int k=f;k<n;k++){
						int o=k-f;
						a[k]=a[i+o];
					}
				}
			}
			
		}
		for(int j=1;j<=n;j++){
			if(a[j]==i){
				r++;
			}
		}
		cout<<r<<" ";
		r=0;
	}
	
	
	return 0;
}
