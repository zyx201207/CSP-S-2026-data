#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],s[N];
int bin_search(int i){
	int l=1,r=i+1,ans=i;
	while(l<r){
		int mid=(l+r)>>1;
//		cout<<"i:"<<i<<" mid:"<<mid<<" a[mid]:"<<a[mid]<<" a[i]*(i-mid)-(s[i-1]-s[mid-1]):"<<
//		a[i]*(i-mid)-(s[i-1]-s[mid-1])<<'\n';
		if(a[i]*(i-mid)-(s[i-1]-s[mid-1])<=m){
			r=mid;
			ans=min(mid,ans);
		}else{
			l=mid+1;
		}
	}
	return ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=a[i]+s[i-1];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int pos=bin_search(i);
//		cout<<i<<' '<<pos<<'\n';
		ans=max(i-pos+1,ans);
	}
	cout<<ans<<'\n';
	return 0; 
} 
/*5 5
1 2 4 8 9
*/