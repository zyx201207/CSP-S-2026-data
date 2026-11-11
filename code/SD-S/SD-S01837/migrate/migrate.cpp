#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r+",stdin);
	freopen("migrate.out","w+",stdout);
	long long c,t,n,d,ji=0,zz=0,zf=0;
	cin>>c>>t;
	
	for(int i=0;i<t;i++){
		cin>>n>>d;
		long long a[n];
	
		for(int j=0;j<n;j++){
		cin>>a[j];
		}
			for(int f=0;f<n;f++){
		if(a[f]<0){
			ji++;
		}
		}
		
			if((n-ji)%d==0){
			zz=(n-ji)/d-1;
		}else{
			zz=(n-ji)/d;
		}
		
		if(ji>0){
			if(ji%d==0){
			zf=(ji/d)-1;
		}else{
			zf=ji/d;
		}
		}
			
		cout<<zf+zz<<endl;
		
		
	}
	
	

	fclose(stdin);
	fclose(stdout); 


	return 0;

} 
