#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mn=5e5+10;
int a[mn],cha[mn],c;
int n,m,l=0x3f3f3f3f,r=-1e9;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		l=min(l,a[i]);
		r=max(r,a[i]);
	}
	while(l<r){
		int mid=(l+r)/2;
		int sum=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(mid-a[i]<0){
				continue;
			}
			sum+=(mid-a[i]);
			ans++;
		}
		if(sum>m){
			r=mid;
		}else{
			l=mid+1;
			c=ans;
		}
	}
	cout << c;
	return 0;
}
