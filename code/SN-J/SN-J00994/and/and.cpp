#include <bits/stdc++.h>
using namespace std;
int n,m,ans = -1;
int a[1000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i = 0;i<n;i++){
			ans = max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	cout<<a[n-1];
	return 0;
}
