#include<bits/stdc++.h>
using namespace std;
long long a[2000001],n,ans;
char b[2000001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	
	long long i=1,j=n;
	while(i<j){
			
			if(a[i]>=a[j]){
				if(b[i]!=b[j])
				ans+=a[j];
				j--;
				
			
				if((a[i]-a[j+1])==0)  {
					i++;
					
				}				
				else a[i]-=a[j+1];
				
			}
			if(a[j]>a[i]){
				if(b[i]!=b[j])
				ans+=a[i];
				i++;
				a[j]-=a[i-1];
				
			}
			
			
	
	
	}
	
	cout<<ans;
	return 0;
}