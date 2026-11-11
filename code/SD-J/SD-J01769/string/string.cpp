#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005];
char c[200005];
int main(){
	ios::sync_with_stdio(0),cin.tie(),cout.tie();
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int top=n;
	ll ln=0;
	ll cnt=0;
	for(int i=1;i<=n;i++){
			cin>>a[i]>>c[i];
	cnt+=a[i];
	} 
	
	int l=1,r=top;
	ll ans=0;
	while(l<r){
		if(a[l]<a[r]){
			if(c[l]!=c[r]){
				ans+=a[l];
			}
			a[r]-=a[l];
			ln+=a[l];
			l++;
		}
		if(a[l]>a[r]){
			if(c[l]!=c[r]){
				ans+=a[r];
			}
			a[l]-=a[r];
			ln+=a[r];
			r--;
		}
		if(a[l]==a[r]){
			if(c[l]!=c[r]){
				ans+=a[l];
			}
			ln+=a[l];
			l++;
			r--;
		}
	
	}
	
	
	cout<<ans<<'\n';
	return  0;
}
