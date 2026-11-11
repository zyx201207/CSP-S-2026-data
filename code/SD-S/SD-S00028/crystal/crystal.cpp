#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],l,r,nw,ans;
inline bool czj(int i){
	if(nw<=m)return 0;
	if(a[i]-a[l]>a[r]-a[i])nw-=a[i]-a[l],l++;
	else nw-=a[r]-a[i],r--;
	return 1;
}
inline bool jzc(int i){
	int flg,t;
	if(a[i]-a[l-1]>a[r+1]-a[i])t=a[i]-a[l-1],flg=0;
	else t=a[r+1]-a[i],flg=1;
	if(nw+t>m)return 0;
	nw+=t;
	if(flg)r++;
	else l--;
	return 1; 
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n),l=r=1,a[0]=-4e12,a[n+1]=4e12;
	for(int i=1;i<=n;i++){
		while(czj(i));
		while(jzc(i));
		ans=max(ans,r-l+1);
		if(i<n)nw+=(i*2+1-l-r)*(a[i+1]-a[i]);
		if(r==i)r++;
	}
	cout<<ans;
	return 0;
}
