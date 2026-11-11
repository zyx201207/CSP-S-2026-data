#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long ll;
int n;
ll m,a[N],pre[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i,mid,pos;
		while(l<=r){
			mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(pre[i]-pre[mid-1])<=m) r=mid-1,pos=mid;
			else l=mid+1;
		}
		ans=max(ans,i-pos+1);
	}
	cout<<ans<<"\n";
	return 0;
}