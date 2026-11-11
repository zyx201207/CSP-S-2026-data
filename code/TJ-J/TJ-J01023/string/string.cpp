#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin)
	freopen("string.out","w",stdout)
	int n;
	string c[100],S[100];
	cin>>n;
	int i,j,k,m,a[100],sum=0;
	for(i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		for(j=1;j<=a[i];j++){
			
			S[j]=c[i];
		}
	sum+=a[i];
		
	
		
	}
	m=sum/2; 
	for(k=1;k<=m;k++){
		if(S[k]==S[sum]){
			sum--;
		}
		else cout<<sum;
		
	}
	cout<<sum;
	
	
	
	
	
	
	fclose(stdin)
	fclose(stdout)
	
	
	
	
	return 0;
	
}
