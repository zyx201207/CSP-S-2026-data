#include<bits/stdc++.h>
using namespace std;
int a[200005];
int ans;
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==n){
		ans=a[1]&a[0];
		for(int i=2;i<n;i++){
			ans&=a[i]&a[i-1];
		}
		cout<<ans;
	}
	if(m==1){
		ans=0;
		for(int i=0;i<n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}
	if(n<=20){
		int mn=2147483647;
		for(int i=0;i<n;i++){
			mn=min(a[i],mn);
		}
		cout<<mn;
	}
	return 0;
}