#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],max1;
int ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];max1=max(a[i],max1);}
	if(m==1){cout<<max1;return 0;}
	else if(m==n){	
		ans=a[1];
		for(int i=2;i<=n;i++)ans=ans & a[i];
		cout<<ans;
		return 0;
	}else if(m==2){
		ans=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				int s=a[i] & a[j];
				ans=max(ans,s);
			}
		}
		cout<<ans;
		return 0;
	}else{
		
	}
	return 0;
}
