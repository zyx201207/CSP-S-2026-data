#include<bits/stdc++.h>
using namespace std;

int a[1001],c[1001];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int b=0;
	int n,m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==m){
			b++; 	
	}
	}
	cout<<b;
	fclose(stdin);
	fclose(stdout);
	return 0;
}; 
