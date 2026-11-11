#include <bits/stdc++.h>
using namespace std;
long long a[1000005],m,n,ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	cin>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]>ans){
				ans=a[i];
			} 
		}
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if((a[i]&a[j])>ans){
					ans=(a[i]&a[j]);
				}
			}
		} 
	}
	
	
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

