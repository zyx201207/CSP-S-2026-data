#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
#define int long long
int n,a[N],ans;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r){ 
		if(a[l]==a[r]){ 
			if(c[l]==c[r]){
				l++,r--;
			}
			else{
				ans+=a[l];
				l++,r--;
			}
		}
		
		else if(a[l]>a[r]){
			if(c[l]==c[r]){
				a[l]-=a[r];
				r--;
			}
			else{
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
		}
		
		else if(a[l]<a[r]){ 
			if(c[l]==c[r]){
				a[r]-=a[l];
				l++;
			}
			else{
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}
		}
//		cout<<ans<<' '<<ll<<' '<<rr<<' '<<l<<' '<<r<<endl;
	}
	cout<<ans;
	return 0;
} 
