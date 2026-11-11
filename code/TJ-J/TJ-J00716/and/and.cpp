#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a[200005],n,m,ans=0;
	cin>>n>>m; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1 && m!=n){
		for(int i=1;i<=n;i++){
			ans=max(a[i],ans);
		}
		cout<<ans;
	}
	if(m==2 && m!=n){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				ans=max(a[i],a[j]);
			}	
		}
		cout<<ans;
		
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			a[i+1]=a[i]&a[i+1];
		}
		ans=a[n];
		cout<<ans;
	}
	return 0;
}
