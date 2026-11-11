#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500010];
int f[500010];
bool cmp(int p,int q){
	return p>q;
}
bool check(int st,int ed){
	int res=a[st]*(ed-st+1)-f[ed]+f[st-1];
	return res<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+a[i];
	}int tot=-1;
	for(int i=1;i<=n;i++){
		int l=i,r=n;
		int mid=(l+r)>>1;
		int ans=-1;
		while(l<=r){
			mid=(l+r)>>1;
			if(check(i,mid)){
				ans=max(ans,mid);
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		tot=max(tot,ans-i+1);
	}
	cout <<tot;
	return 0;
}
