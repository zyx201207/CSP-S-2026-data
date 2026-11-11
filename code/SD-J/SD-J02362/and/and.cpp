#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int a[N];
signed main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		for(int i=2;i<=n;i++){
			a[i]=(a[i-1])&a[i];
		}
		for(int i=1;i<=n;i++){
			cout<<a[i];
		}
	}
	else if(m==1){
		int maxx=-1e9;
		for(int i=1;i<=n;i++){
			maxx=max(a[i],maxx);
		}
		cout<<maxx;
	} 
	else if(m==2){
		int maxx=-1e9;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j!=i){
					maxx=max(a[i]&a[j],maxx);
				}
			}
		}
		cout<<maxx;
	}
	else{
		int maxn;
		while(m--){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					int maxx=-1e9;
					if(m==m-1&&j!=i){
						maxn=a[i]&a[j];
					}
					else if(j!=i){
						maxx=max(a[i]&a[j],maxx);
						maxn=maxx;
					}
				}
			}
		}
		cout<<maxn; 
	}
	return 0;
} 
