#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000005],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	while(m--){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i]%a[j]>ans){
					ans=a[i]%a[j];
				}
			}
		}	
	}
	cout << ans;
	return 0;
} 
