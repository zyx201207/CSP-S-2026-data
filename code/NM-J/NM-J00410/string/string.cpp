#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,a=0,b=0,cc=0;
	char c[100000005],e,nb[100000005];
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>a>>e;
		b=b+a;
		for(int j=1;j<=a;j++){
			c[j]=e;
			
		}
	} 
	
		if(b%2==1){
			for(int i=1;i<=b/2-1;i++){
				nb[i]=c[i];
			}
		}
		else{
			for(int i=1;i<=b/2;i++){
			
				nb[i]=c[i];
		}
		}
		if(b%2==1){
			for(int i=b/2-1;i>=1;i--){
				int ppp;
				ppp++;
				if(c[i]!=nb[ppp]){
					cc++;
				}
			}
		}
		else{
			for(int i=b/2;i>=1;i--){
				int ppp;
				ppp++;
				if(c[i]!=nb[ppp]){
					cc++;
				}
			}
		}
	cout<<cc;




	return 0;
}