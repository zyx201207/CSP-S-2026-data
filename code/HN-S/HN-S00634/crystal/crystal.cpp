#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,M=1e12;
int n,m,a[N],b[N],ans,sum[N];
int find(int x){
	int l=1,r=x,mid,eps=b[x],cnt=0;
	while(l<=r){
		mid=(l+r)/2;
		int res=sum[x]-sum[mid-1]-eps*(x-mid+1);
		if(res<=m){
			cnt=x-mid+1;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	} 
	return cnt;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=M-a[i];
	} 
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+b[i];
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,find(i));
	}
	cout<<ans;
	return 0;
} 
