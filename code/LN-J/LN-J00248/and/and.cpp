#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a[200005]={0};
	int m,n,ans=0;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]&0);
		}
		cout << ans;
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout << ans;
		return 0;
	}if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=2;j<=n;j++){
				i=i&j;
			}
			ans=i;
		}
		cout << ans;
	}
	return 0;
}
