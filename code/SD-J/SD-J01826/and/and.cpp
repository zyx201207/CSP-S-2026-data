#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}cout<<ans;
	}
	else if(m==n){
		for(int i=2;i<=n;i++){
			a[i]&=a[i-1];
		}
		cout<<a[n];
	}
	else{
		if(m==2){
			for(int i=2;i<n;i++){
				for(int j=1;j<i;j++){
					a[i]&=a[j];
				}
			}
			cout<<a[n];
		}else{
			for(int i=1;i<=m;i++){
				for(int j=m;j<=n;j++){
					a[j]&=a[i];
				}
			}
			cout<<a[m];
		}
	}
	return 0;
}
