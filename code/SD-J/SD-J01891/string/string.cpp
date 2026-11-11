#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10; 
int n,a[N],ans;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}int l=1,r=n,ll=a[1],rr=a[n];
	while(l<r){
		if(ll==rr){
			if(c[l]!=c[r]){
				ans+=ll;
			}
			l++;r--;ll=a[l];rr=a[r];
		}else if(ll>rr){
			if(c[l]!=c[r]){
				ans+=rr;
			}
			ll=ll-rr;
			r--;
			rr=a[r];
		}else{
			if(c[l]!=c[r]){
				ans+=ll;
			}
			rr=rr-ll;
			l++;ll=a[l];
		}
	}cout<<ans;
	return 0;
}
