#include<iostream>
#include<cstdio>
using namespace std;
long long m,n,a[5005],b[5005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			b[j]=a[j];
			
		} 
	}
	return 0;
} 
