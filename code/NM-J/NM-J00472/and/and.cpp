#include<bits/stdc++.h>
using namespace std;

int main(){
	
	foreopen("and.in","r",stdin);
	foreopen("and.out","w",stdout);

	long long int n,m,zd=0;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];	
		if(a[i]>zd) zd=a[i];		
	}
	if(m==1) {cout<<zd;
		return 0;
	}
	zd=0;
	
	if(m==2){
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				if((a[i]&a[j])>zd)
					zd=a[i]&a[j];			
			}
		}
		cout<<zd;
		return 0;
		
		
		
	}
	
	
	for(int i=0;i<n-m;i++){	
		for(int j=0;j<m;j++){
			for(int k=i+m;k<n;k++)	
				if((a[i]&a[k])>zd){
					zd=a[i]&a[j];
					
				}
		}			
	}

	cout<<zd;




	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
