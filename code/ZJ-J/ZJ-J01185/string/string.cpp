#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,a[200010];
char c[200010];
ll ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int l=1,r=n;l<r;){
		int ls=min(a[l],a[r]);
		if(c[l]!=c[r]){
			ans+=ls;
		}
		a[l]-=ls,a[r]-=ls;
		if(a[l]==0){
			l++;
		}
		if(a[r]==0){
			r--;
		}
	}
	cout<<ans;
	return 0; 
}
