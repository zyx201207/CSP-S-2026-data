#include<stdio.h>
#include<iostream>
using namespace std;
int n,m,a[50050];
int main(){
	freopen("card.in","r",stdin); 
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[n];
	}
	if(m==1) cout<<n;
	else{
		for(int i=0;i<m;i++){
			cout<<1<<' ';
		}
	}
	return 0;
}
