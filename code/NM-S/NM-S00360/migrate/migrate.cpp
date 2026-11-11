#include<bits/stdc++.h>
using namespace std;
int main(){
 	
	int c,t; 
	cin>>c>>t;
	
	while(t){
		int n,k;
		int u[10005];
		int m[10005];
		int ans[10005] = {0};
		int c = 0;
		cin>>n>>k;
		for(int i = 1;i<=n;i++){
			cin>>u[10]>>m[10];
			//cout<<i;
			ans[i]+=ans[m[i]-u[i]]++;
		}
			for(int i = 1;i<=n;i++){
				if(ans[i]<=k)
					c = i;
				break;
			}
	
	
	
	
		t--;
		cout<<c<<endl;
		cout<<c+1; 
		
	
	
	
	}		
					
				
			

	

	
	


	
	return 0;
}


