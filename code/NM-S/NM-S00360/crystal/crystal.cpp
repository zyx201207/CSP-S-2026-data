	
#include<bits/stdc++.h>
using namespace std;
int main(){ 	
	int n,m,a[500000];
	cin>>n>>m;	
	for(int i = 0;i < n; i++){
		cin>>a[i];			
	} 
	while(m){
		for(int j = m; j > 0; j-- ){
			if(a[j+1]-a[j]){
				m-n == j*(a[j+1]-a[j]);
				cout<<a[j];
				}				
			}
		m--;
		}
		
	return 0;
}
	
	

	
	


	
	



