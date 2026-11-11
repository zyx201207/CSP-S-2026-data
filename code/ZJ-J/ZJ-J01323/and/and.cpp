#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=31;i>=1;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if( ((a[j]&ans)==ans) && ((a[j]>>(i-1))&1) ) cnt++;
		}
		if(cnt>=m) ans+=(1<<(i-1));
	}
	cout<<ans;
	return 0;
}