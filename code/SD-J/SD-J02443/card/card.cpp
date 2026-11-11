#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	int n,m,a[5009],w=0,b[50009],c[50009],o;
	cin>>n>>m;
	o=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}  
	while(o!=0){	
	for(int j=0;j<n-j+1;j++){
	b[j]=a[j];
	w++;
	for(int i=0;i<j;i++){
		if(b[i]==b[j]){
			w=w-j+i;
			continue;
		}
	}
	
	}
	w=0;
	o--;
	}
	return 0;
}
