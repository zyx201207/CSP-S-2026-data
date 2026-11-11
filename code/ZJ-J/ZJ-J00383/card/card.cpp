#include<bits/stdc++.h>
using namespace std;
int n,m,a[5000005],x[5000005]={},s=0,f=0;
int t[3000005]={};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int ii=0;ii<n;ii++){
		for(int jj=0;jj<=(n-ii);jj++)x[jj]=0;
		s=0; 
		for(int i=ii;i<n;i++){
			f=0;
			for(int j=0;j<s;j++){
				if(x[j]==a[i]){
					for(int k=j;k<s;k++)x[k]=0;
						s=j;   
						x[s]=a[i];
						f=1;
						break;        
				}
			}
			if(f==0){
				x[s]=a[i];
			}
			s++;	  			 	                
		}		
		for(int l=0;l<s;l++){
			t[x[l]]+=1;	
		}
	}
	for(int i=1;i<=m;i++)cout<<t[i]<<" ";
	return 0;
}