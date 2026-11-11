#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10;
int n,m;
int a[N];
int ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	} 
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			ans=max(ans,(a[i]&a[j]));
		} 
	}
	cout<<ans;
	return 0;
} 
