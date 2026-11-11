#include<bits/stdc++.h>
#define int long long
using namespace std;
string s1,c1,s2,c2;
const int N=2e5+5;
int n,a[N],ans;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	for(int l=1,r=n;l<=r;){
		if(c[l]==c[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}else{
				l++;
				r--;
			}
		}else{
			if(a[l]>a[r]){
				a[l]-=a[r];
				ans+=a[r];
				r--;
			}else if(a[l]<a[r]){
				a[r]-=a[l];
				ans+=a[l];
				l++;
			}else{
				ans+=a[l];
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}