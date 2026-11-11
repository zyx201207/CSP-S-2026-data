//郝苑博 延安市新区第一中学 SN-J00851 
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,a,cnt=0,cont=0;
	char c,b[100005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		if(cont==0){
			for(int j=1;j<=a;j++){
					b[cont]=c;
					cont++;	
			}
				
		} 
		else{
			for(int j=1;j<=a;j++){
					b[cont-1]=c;
					cont++;	
			}
		}	
	}
	cout<<"0"; 
	return 0;
}
