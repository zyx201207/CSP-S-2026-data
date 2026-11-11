#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[200005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}else if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n];
	}else if(m==2){
		int ans=a[1]^a[2];
		for(int i=2;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}else if(m==2){
		int ans=a[1]&a[2]&a[3];
		for(int i=2;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					ans=max(ans,a[i]&a[j]&a[k]);
				}
			}
		}
		cout<<ans;
	}else if(m==n-1){
		int b[200005];
		for(int i=1;i<=n;i++){
			b[i]=a[i];
		}
		for(int i=2;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j!=i){
					b[i]=b[i]&a[j];
				}
			}
		}
		sort(b+1,b+1+n);
		cout<<b[n];
	}
	fclose(stdin);
	fclose(stdout);
}
