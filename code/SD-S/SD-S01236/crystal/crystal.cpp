#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],s[N];
bool check(int p,int mid){
	int v=(p-mid)*a[p]-(s[p-1]-s[mid-1]);
	if(v<=m) return 1;
	return 0;
} 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		int l=1,r=i-1;
		int cnt=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(i,mid)){
				cnt=mid,r=mid-1;
			}else l=mid+1;
		}
		if(!cnt) continue;
		ans=max(i-cnt+1,ans);
	}
	cout<<ans;
	return 0;
}

