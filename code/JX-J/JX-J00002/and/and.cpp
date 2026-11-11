#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[2000005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
        cin>>a[i];
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}
	if(m==1){
		int maxn=-1;
		for(int i=1;i<=n;i++){
			maxn=max(a[i],maxn);
		}	
		cout<<maxn;
	}
	if(m==2){
		int maxn=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(a[i]&a[j],maxn);
			}
		}
		cout<<maxn;
	}
	if(m==n-1){
		int maxn=-1;
		for(int i=1;i<=n;i++){
			if(i==1){
				int x=a[2];
				for(int j=3;j<=n;j++){
					if(j==i){
						continue;
					}
					x&=a[j];
				}
				maxn=max(maxn,x);	
			}
			else{
				int x=a[1];
				for(int j=2;j<=n;j++){
					if(j==i){
						continue;
					}
					x&=a[j];
				}
				maxn=max(maxn,x);
			}
		}
		cout<<maxn;
	}
	return 0;
}
