#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],cnt;
void cmp(int l,int r){
	if(l>r)return;
	long long mid=(l+r)>>1,ans=0;
	bool b=false;
	for(int i=1;i<=mid;i++)ans+=a[mid]-a[i];
	if(ans<=m)b=true;
	for(int i=mid+1;i<=n;i++){
		ans+=(a[i]-a[i-1])*mid-(a[i]-a[i-mid]);
		if(ans<=m)b=true;
	}
	if(b){
		cnt=mid;cmp(mid+1,r);
	}else cmp(l,mid-1);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	cmp(1,n);
	cout<<cnt;
	return 0;
}