#include<bits/stdc++.h>
using namespace std;

int a[1005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,z=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int l=0;l<n;l++){
		for(int j=0;j<n;j++){
			if(a[l]==a[j]){
				z++;
			}
			
		}
		cout<<z;
	}
	return 0;
}