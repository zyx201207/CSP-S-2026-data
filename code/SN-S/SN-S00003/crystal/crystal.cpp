#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen ("crystal.in","r",stdin);
	freopen ("crystal.out","w",stdout);
	int n,m,t,y;
	cin>>n>>m;
	int result;
	int a[100];
	int a1[100][100];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
	   for(int j=1;j<=n;j++){
	   	a1[i][j]=a[j]-a[i];
	   if(a1[i][j]<0){
	   	a1[i][j]=a[i]-a[j];
	   }
	   }		
	}
	
	
	for(int i=1;i<=n;i++){
		int q=0;
		int total=0;
	   for(int j=1;j<=n;j++){
	   	
	   	
		   
	   	q=q+a1[j][i];
	   	total++;
	   	
	   	if(q==m){
	   		
	   		if(j<i){
			   
	   		result=total+1;
	   		
		   }
		   else result=total;
		   	
		   
	   }
	   
	   }
	
	}
	
	
		cout<<result;
	
	return 0;
}
