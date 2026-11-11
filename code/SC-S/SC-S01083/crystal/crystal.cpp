#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n,ans=1;
ll m,a[N],s[N];
int search(int lim){
	int l=1,r=lim-1;
	while(l<=r){
		int mid=l+r>>1;
		if(a[lim]*(lim-mid+1)-s[lim]+s[mid]<=m) r=mid-1;
		else l=mid+1;
	}
	return r+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		a[i]-=a[1];
		s[i]=s[i-1]+a[i];
	}
	for(int i=2;i<=n;i++){
		int pos=search(i);
		ans=max(ans,i-pos+1);
	}
	cout<<ans;
	return 0; 
}