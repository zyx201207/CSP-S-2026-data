#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,l,r,ans,a[200010];
char s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>s[i];
	if(n==1){
		cout<<0;
		return 0;
	}
	l=1;
	r=n;
	while(l<r){
		if(s[l]==s[r]){
			if(a[l]==a[r]){
				l++;
				r--;
			}
			else if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
			else{
				a[r]-=a[l];
				l++;
			}
		}
		else{
			if(a[l]==a[r]){
				ans+=a[l];
				l++;
				r--;
			}
			else if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
			else{
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
