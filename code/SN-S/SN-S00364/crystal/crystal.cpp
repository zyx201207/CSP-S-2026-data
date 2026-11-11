//南亭序 西安市第二十五中学 SN-S00364
#include <bits/stdc++.h>
#define int long long 
using namespace std;
int n,a[500005],m,s[500005],mx;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i] = a[i]+s[i-1];
	}
	
	for(int i=1;i<=n;i++){
		int l=1,r=i-1,mid=(l+r+1)/2;
		while(r!=mid){
			if(a[i]*(i-mid)-(s[i-1]-s[mid-1])<=m){
				r=mid;
			}else{
				l=mid;
			}
			mid = (l+r+1)/2;
		}
		mx = max(mx,i-mid+1);
	}
	cout <<mx;
	return 0;
}
