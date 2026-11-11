#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10; 
int n,l,r,ans;
int a[N];
char c[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	l=1,r=n;
	while(l<=r){
		if(c[l]==c[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
				continue;
			}
			if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
				continue;
			}
			if(a[l]==a[r]){
				l++;
				r--;
				continue;
			}
		}
		else{
			if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
				continue;
			}
			if(a[l]<a[r]){
				ans+=a[l];
				a[r]-=a[l];
				l++;
				continue;
			}
			if(a[l]==a[r]){
				ans+=a[l];
				l++;
				r--;
				continue;
			}
		}
	}
	cout<<ans;
	return 0;
}
