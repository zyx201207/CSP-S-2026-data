#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m,a[200005],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=1;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		unsigned long long aans;
		a[n+1]=a[1];
		for(int i=1;i<=n;i++){
			aans=a[i+1];
			for(int j=1;j<=n;j++){
				if(j!=i)aans=aans&a[j];
			}
			ans=max(ans,aans);
		}
		cout<<ans;
		return 0;
	}
	cout<<a[n-m+1];
	return 0;
} 
