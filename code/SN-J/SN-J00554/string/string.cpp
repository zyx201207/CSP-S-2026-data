#include<bits/stdc++.h>
using namespace std;
long long n,m,j=0,sum=0,ans,o[1000000],ii;
char a[1000000],b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>o[i]>>a[i];
		
	}
	ii=n-1;
	for(int i=0;i<n;){
		if(a[i]==a[ii]){
			if(o[i]>o[ii]){
				o[i]-=o[ii];
				ii--;
			}else if(o[i]<o[ii]){
				o[ii]-=o[i];
				i++;
			}else{
				ii--;
				i++;
			}
			
		}else if(o[i]>o[ii]){
			//a[ii]=a[i];
			ans+=o[ii];
			o[i]-=o[ii];
			ii--;
			
		}else if(o[i]<o[ii]){
			//a[i]=a[ii];
			ans+=o[i];
			//cout<<o[i]<<" "<<o[ii];
			o[ii]-=o[i];
			i++;
			
			
		}else{
			ans+=o[i];
			ii--;
			i++;
			
		}
		if(ii<=i){
			break;
		}
		
	}
	cout<<ans;
	return 0;
} 
