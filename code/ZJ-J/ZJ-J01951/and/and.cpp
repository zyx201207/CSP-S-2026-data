#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200010];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i=1 ; i<=n ; i++) cin >> a[i];
	if (m==1){
		int maxx=0;
		for (int i=1 ; i<=n ; i++){
			maxx=max(maxx,a[i]);
		}
		cout << maxx;
	}
	else if (m==2){
		int maxx=0;
		for (int i=1 ; i<=n ; i++){
			for (int j=i+1 ; j<=n ; j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout << maxx;
	}
	else if (m==3){
		int maxx=0;
		for (int i=1 ; i<=n ; i++){
			for (int j=i+1 ; j<=n ; j++){
				for (int k=j+1 ; k<=n ; k++){
					maxx=max(maxx,a[i]&a[j]&a[k]);
				}
			}
		}
		cout << maxx;
	}
	else if (m==4){
		int maxx=0;
		for (int i=1 ; i<=n ; i++){
			for (int j=i+1 ; j<=n ; j++){
				for (int k=j+1 ; k<=n ; k++){
					for (int u=k+1 ; u<=n ; u++){
						maxx=max(maxx,a[i]&a[j]&a[k]&a[u]);
					}
				}
			}
		}
		cout << maxx;
	}
	else if (m==5){
		int maxx=0;
		for (int i=1 ; i<=n ; i++){
			for (int j=i+1 ; j<=n ; j++){
				for (int k=j+1 ; k<=n ; k++){
					for (int u=k+1 ; u<=n ; u++){
						for (int x=u+1 ; x<=n ; x++){
							maxx=max(maxx,a[i]&a[j]&a[k]&a[u]&a[x]);
						}
					}
				}
			}
		}
		cout << maxx;
	}
	else if (m==6){
		int maxx=0;
		for (int i=1 ; i<=n ; i++){
			for (int j=i+1 ; j<=n ; j++){
				for (int k=j+1 ; k<=n ; k++){
					for (int u=k+1 ; u<=n ; u++){
						for (int x=u+1 ; x<=n ; x++){
							for (int y=x+1 ; y<=n ; y++){
								maxx=max(maxx,a[i]&a[j]&a[k]&a[u]&a[x]&a[y]);
							}
						}
					}
				}
			}
		}
		cout << maxx;
	}
	else if (m==n){
		int maxx=a[1];
		for (int i=2 ; i<=n ; i++){
			maxx=maxx&a[i];
		}
		cout << maxx;
	}
	else if (m==n-1){
		int maxx=0,ans=0;
		for (int i=1 ; i<=n ; i++){
			if (i==1) ans=a[2];
			else ans=a[1];
			for (int j=1 ; j<=n ; j++){
				if (j!=i) ans=ans&a[j];
			}
			maxx=max(maxx,ans);
		}
		cout << maxx;
	}
	return 0;
}
