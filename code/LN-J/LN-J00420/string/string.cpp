#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
char a[N];
ll nn[N];
ll n,l,r,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>nn[i]>>a[i];
	l=1,r=n;
	while(l<=r){
		if(nn[l]==nn[r]){
			if(a[l]==a[r]){
				l++;
				r--;
			}
			else{
				if(a[l+1]==a[r]){
					ans+=nn[l];
					l++;
				}
				else{
					ans+=nn[r];
					r--;
				}
			}
		}
		else if(nn[l]>nn[r]){
			if(a[l]!=a[r]) ans+=nn[l]-nn[r];
			nn[l]-=nn[r];
			r--;
		}
		else{
			if(a[l]!=a[r]) ans+=nn[r]-nn[l];
			nn[r]-=nn[l];
			l++;
		}
	}
	cout<<ans;
	return 0;
}
