#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int n,m,a[N],pre[N],len1,len2,sum[N],op[N],kl[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int ans=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]<0)op[++len1]=a[i];
		else kl[++len2]=a[i];
	}
	sort(op+1,op+1+len1);
	sort(kl+1,kl+1+len2);
	for(int i=1;i<=len1;++i){
		pre[i]=pre[i-1]+op[i];
	}
	for(int i=1;i<=len2;++i){
		sum[i]=sum[i-1]+kl[i];
	}
	for(int i=1;i<=len1;++i){
		int l=1,r=i;
		while(l<r){
			int mid=l+r>>1;
			int len=i-mid+1;
			if(len*op[i]-(pre[i]-pre[mid-1])<=m)r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	for(int i=1;i<=len2;++i){
		int l=1,r=i;
		while(l<r){
			int mid=l+r>>1;
			int len=i-mid+1;
			if(len*kl[i]-(sum[i]-sum[mid-1])<=m)r=mid;
			else l=mid+1;
		}
		if(l==1){
			int L=1,R=len1;
			while(L<R){
				int mid=L+R>>1;
				int len=len1-mid+1;
				if(i*kl[i]-sum[i] + len*kl[i] - (pre[len1]-pre[mid-1])<=m)R=mid;
				else L=mid+1;	
			}
			int len=len1-L+1;
			if(i*kl[i]-sum[i]+len*kl[i]-(pre[len1]-pre[L-1])<=m){
				ans=max(ans,i+len1-L+1);
			}
//			cout<<i<<' '<<i*kl[i]-sum[i]+len*kl[i]-(pre[len1]-pre[l-1])<<'\n';
		}
		ans=max(ans,i-l+1);
		
	}
	cout<<ans;
	return 0;
}
