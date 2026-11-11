#include<bits/stdc++.h>
#define lon long long
using namespace std;
const int N=500010;
const lon M=1e18;
int n;
lon m;
lon a[500010];
lon qz[500010];
lon ans;
int l,r,mid;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		qz[i]=qz[i-1]+a[i];
		l=1;
		r=i;
		while(l<r){
			mid=l+r>>1;
			if(m>=(a[i]*(i-mid)-(qz[i-1]-qz[mid-1]))) r=mid;
			else l=mid+1;
		}
		ans=max(ans,(lon)i-l+1);
	}
	cout<<ans;
	return 0;
}//但行前路终无悔,须知万事在人为 .
