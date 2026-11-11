#include <bits/stdc++.h>
using namespace std;
const int N=1e6+1000;
int pre[N][20],a[N],lg[N],cha[N],tt[N],n,m;
long long as[N],qian[N];
signed main()
{
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];a[i+n]=a[i];
	}
	lg[1]=0;
	for(int i=2;i<=n;i++) lg[i]=lg[i-1]+((1<<(lg[i-1]+1))==i);
	n=n*2;
	for(int i=n;i>=1;i--){
		pre[i][0]=tt[a[i]];
		tt[a[i]]=i;
	}
	for(int i=1;i<=lg[n];i++){
		for(int j=1;j+(1<<i)-1<=n;j++){
			pre[j][i]=max(pre[j][i-1],pre[j+(1<<(i-1))][i-1]);
		}
	}
	for(int i=n/2;i<n;i++){
		cha[i+1]--;
		long long l=i-n+1,r=i,ma,ans=0;
		while(l<=r){
			long long mid=(l+r)>>1;
			long long k=lg[mid-l+1];
			ma=max(pre[l][k],pre[mid-(1<<k)+1][k]);
			if(ma>mid) l=mid+1;
			else if(ma<mid){
				ans=mid;
				r=mid-1;
			}
			if(ma==i){
				ans=i;
				break;
			}
		}
		cha[ans]++;
		cout<<ans<<endl;
	}
	for(int i=1;i<=n;i++){
		qian[i]=qian[i-1]+cha[i];
	}
	for(int i=1;i<=n;i++){
		as[a[i]]+=qian[i];
	}
	for(int i=1;i<=m;i++) cout<<as[i]<<" ";
	return 0;
}
/*
4 3
1 2 1 3
*/