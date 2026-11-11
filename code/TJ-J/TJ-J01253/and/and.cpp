#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll m,n;
ll a[200005];
ll ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 0;i<n;i++)cin >> a[i];
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				ans = max(ans,a[i]&a[j]);
			}
		}
	}else if(m==3){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					ans = max(ans,a[i]&a[j]&a[k]);
				}
			}
		}
	}

	cout << ans << "\n";
	return 0; 
} 
