#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[200010],ans;
char c[200010];
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cout.tie(0),cin.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	int r=n,l=1;
	for(;l<r;){
		if(c[l]!=c[r]){
			if(a[l]<a[r]){
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}else if(a[r]<a[l]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}else if(a[r]==a[l]){
				ans+=a[l];
				l++;
				r--;
			}
		}else{
			if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}else if(a[r]<a[l]){
				a[l]-=a[r];
				r--;
			}else{
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
