#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans=0,x=0;
int a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			x=(x&a[i]);
		}
		ans=x;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			x=(a[i]&a[j]);
			if(x>ans){
				ans=x;
			}
		}
	}
	cout<<ans;
	return 0;
}
