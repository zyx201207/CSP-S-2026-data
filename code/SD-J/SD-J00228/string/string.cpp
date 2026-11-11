#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,a[N];
char c[N];
int cnt;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int l=1;
	int r=n;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}else if(a[l]==a[r]){
				l++;
				r--;
			}
		}else{
			if(a[l]>a[r]){
				a[l]-=a[r];
				cnt+=a[r];
				r--;
			}else if(a[l]<a[r]){
				a[r]-=a[l];
				cnt+=a[l];
				l++;
			}else if(a[l]==a[r]){
				cnt+=a[l];
				l++;
				r--;
			}
		}
	}
	cout<<cnt;
	return 0;
}
