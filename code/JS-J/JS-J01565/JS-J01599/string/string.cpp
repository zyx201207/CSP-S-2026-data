#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],cnt=0;
char c[200005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<r){
		if(a[l]>a[r]){
			if(c[l]!=c[r]) cnt+=a[r];
			a[l]-=a[r];
			r--;
		}if(a[l]==a[r]){
			if(c[l]!=c[r]) cnt+=a[r];
			l++;
			r--;
		}if(a[l]<a[r]){
			if(c[l]!=c[r]) cnt+=a[l];
			a[r]-=a[l];
			l++;
		}
	}cout<<cnt;
	return 0;
}
