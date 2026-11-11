#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		long long ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					ans=max(ans,a[i]&a[j]);
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		long long ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		long long ans;
		for(int i=1;i<=n;i++){
			long long cnt=a[i+1];
			for(int j=1;j<=n;j++){
				if(j!=i&&j!=i+1){
					cnt=cnt&a[j];
				}
			}
			ans=max(cnt,ans);
		}
		cout<<ans;
		return 0;
	}
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
