#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
ll a[N];
int n,m;
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll mx=INT_MIN;
	if(m==1){
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,a[i]&a[j]);
			}
		}
	}
	if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					mx=max(mx,a[i]&a[j]&a[k]);
				}
			}
		}
	}
	if(m==4){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int x=k+1;x<=n;x++){
						mx=max(mx,a[i]&a[j]&a[k]&a[x]);
					}
				}
			}
		}
	}
	if(m==5){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int x=k+1;x<=n;x++){
						for(int y=x+1;y<=n;y++){
							mx=max(mx,a[i]&a[j]&a[k]&a[x]&a[y]);
						}
					}
				}
			}
		}
	}
	cout<<mx;
	return 0;
}
