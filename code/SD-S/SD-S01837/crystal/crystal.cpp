#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r+",stdin);
	freopen("crystal.out","w+",stdout);
	long long n,m,ji=0;
	bool z=true;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
			if(z==false){
				break;
			}
		for(int j=0;j<i;i++){
		
			while(a[i]!=a[j]){
				if(z==false){
				break;
			}
					
				
				if(m==0){
					cout<<i;
					z=false;
					break;
					
				}
				a[j]++;
				m=m-1;
			}
			
		
	
	}
	
	}

	fclose(stdin);
	fclose(stdout); 

	return 0;
	
} 








