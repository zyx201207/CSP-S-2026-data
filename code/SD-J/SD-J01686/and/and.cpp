#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans=0,ans2=0,ans3=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			
			ans2=max(ans,a[i]&a[j]);
			ans3=ans3&a[i];
		} 
		
	}
	if(m==n){
		cout<<ans3<<endl;
	}else if(m==2){
		cout<<ans2<<endl;
	}
	else{
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}cout<<ans<<endl;
	}
	
	return 0;
}
