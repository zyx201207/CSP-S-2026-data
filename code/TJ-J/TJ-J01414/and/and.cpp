#include<bits/stdc++.h>
using namespace std;
long long a[100005],n,m,ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
	}
	if(m==n){
		ans=a[1]&a[2];
		for(int i=3;i<=n;i++){
			ans=ans&a[i];
		}
	}
	if(m==2){
		int u;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				u=a[i]&a[j];
				ans=max(ans,u);
			}
		}
	}
	cout<<ans;
	return 0;
}
