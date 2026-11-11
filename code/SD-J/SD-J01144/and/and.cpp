#include<bits/stdc++.h>
using namespace std;
int a[200005],n,m,b[500005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n];
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		int maxx=-1e9;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==3){
		int maxx=-1e9;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int x=j;x<=n;x++){
					maxx=max(maxx,a[i]&a[j]&a[x]);
				}
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==4){
		int maxx=-1e9;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int x=j;x<=n;x++){
					for(int k=x;k<=n;k++){
						maxx=max(maxx,a[i]&a[j]&a[x]&a[k]);
					}
				}
			}
		}
		cout<<maxx;
		return 0;
	}
	return 0; 
} 
