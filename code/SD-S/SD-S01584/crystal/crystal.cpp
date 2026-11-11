#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll a[N],qzh[N]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	ll m;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)qzh[i]=qzh[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;++i){
		int l=i,r=n,pos=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if((mid-i+1)*a[mid]-qzh[mid]+qzh[i-1]<=m){
				pos=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		if(pos)ans=max(ans,pos-i+1);
	} 
	printf("%d",ans);
	return 0;
}
