#include<bits/stdc++.h>
using namespace std;
long long n,m,maxv,ans,a[200005],k;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;return 0;
	}else if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;return 0;
	}else if(m==2){
		for(int i=1;i<=n-1;i++){
			ans=a[i];
			for(int j=i+1;j<=n;j++){
			 	ans=(ans&a[j]);
			 	if(ans>maxv) maxv=ans;
			}
		}
		cout<<maxv;return 0;
	}else{
		for(int i=1;i<=n-m+1;i++){
			ans=a[i];
			for(int j=i+1;j<=i+m-1;j++){
			 	ans=(ans&a[j]);
			}
			if(ans>maxv) maxv=ans;
		}
		cout<<maxv;return 0;
	}
	return 0;
}
