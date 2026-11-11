#include <bits/stdc++.h>
using namespace std;
#define N 500000
int n,Cnt[N+5],Suf[N+5],len;
long long m,A[N+5],tem[N+5],Suv[N+5],ans,tem1;
int ffnd(int l,int r,int val){
	for(int mid=(l+r)>>1;l<r;mid=(l+r)>>1){
		if((Suf[mid]-Suf[val])*tem[val]-(Suv[mid]-Suv[val])>m)l=mid+1;
		else r=mid;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>A[i];
	for(int i=1;i<=n;i++)tem[i]=A[i];
	sort(tem+1,tem+n+1),len=unique(tem+1,tem+n+1)-tem-1;
	for(int i=1;i<=n;i++)A[i]=lower_bound(tem+1,tem+len+1,A[i])-tem;
	for(int i=1;i<=n;i++)Cnt[A[i]]++;
	for(int i=len;i>=1;i--)Suv[i]=Suv[i+1]+tem[i]*Cnt[i],Suf[i]=Suf[i+1]+Cnt[i];
	for(int i=1;i<=len;i++){
		tem1=ffnd(1,i,i);
		ans=max(ans,Suf[tem1]-Suf[i+1]+(tem1==1?0:(m-(Suf[tem1]-Suf[i])*tem[i]+(Suv[tem1]-Suv[i]))/(tem[i]-tem[tem1-1])));
	}
	cout<<ans<<"\n";
	return 0;
}
