#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
long long a[N],bpre[N],bprepre[N],ans=1;
bool check(int fr,int bk){
	if(bprepre[fr]-bprepre[bk+1]-(bk-fr+1)*bpre[bk+1]<=m) return 1;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--) a[i]=a[i]-a[i-1];
	a[1]=0;
	for(int i=n;i>=1;i--) bpre[i]=bpre[i+1]+a[i],bprepre[i]=bprepre[i+1]+bpre[i];
	for(int i=n;i>=2;i--){
		int l=2,r=i;
		while(l!=r){
			int mid=(l+r)>>1;
			if(check(mid,i)) r=mid;
			else l=mid+1;
		}
		if(check(r,i)) ans=max(ans,1ll*i-r+2);
	}
	cout<<ans<<"\n";
	return 0;
} 
