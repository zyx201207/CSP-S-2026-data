#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a[i]=x;
	}
	int wwx[n];
	for(int i=0,s=n;i<n;i++,s--){
		wwx[i]=a[i];
		for(int j=0;j<n;j++){
			if(wwx[i]==a[j]){
				
			
			}
		}
	}
	return 0;
}
