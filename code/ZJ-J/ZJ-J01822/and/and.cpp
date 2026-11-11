#include<bits/stdc++.h>
using namespace std;
long long n,m,maxx = -1,x,a[20005];
bool f[20005];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++) cin>>a[i];
	x = a[1];
	if(m == 1){
	for(int i = 1;i<=n;i++) x=max(x,a[i]);	
		cout<<x;
		return 0;
	}
	if(m == n){
		for(int i = 2;i<=n;i++) x = x&a[i];
		cout<<x;
		return 0;
	}
	if(m == 2) {
		x = -1;
		for(int i = 1;i<=n;i++){
			long long s = 0;
			for(int j = i+1;j<=n;j++){
				s = a[i]&a[j];
				x = max(x,s);
			}
		}
		cout<<x;
		return 0;
	}
	for(int qwertyuiop = 1;qwertyuiop<m;qwertyuiop++){
		x = 0;
		int r = 0,l = 0;
		if(qwertyuiop == 1){
			for(int i = 1;i<=n;i++){
				for(int j = i+1;j<=n;j++){
					if(f[i] == 0&&f[i] == 0){
						long long ddd = a[i]&a[j];
						if(ddd>x) r = j,l = i,x = ddd;	
					}	
				}
			}
			maxx = x;
			f[l] = f[r] = 1;
		}
		else{
			for(int i = 1;i<=n;i++){
				if(f[i] == 0){
					long long ddd = maxx&a[i];	
					if(x<ddd) x = ddd,l = i;
				}
				
			}
			maxx = x;
			f[l] = 1;
		}
	}
	cout<<maxx;
	return 0;
}
