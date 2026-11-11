#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
long long m,n,a[N],ans;
int main(){
 	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(a[i]&a[j],ans);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		ans=1;
		for(int i=1;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}
	if(m==n-1){
		long long x;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j!=i){
					x=x&a[i];
				}
			}
			ans=max(ans,x);
		}
		cout<<ans;
	}
	
	return 0;
} 
