#include<bits/stdc++.h>
using namespace std;
int a[200005];
int ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int o=a[i]&a[j];
				ans=max(ans,o);
			}
		}
		cout<<ans;
		return 0;
	}
	int o=1;
	if(m==n-1){
		o=2;
	}
	ans=a[o];
	if(m==n){
		for(int i=o+1;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
	}
	
	return 0;
}
