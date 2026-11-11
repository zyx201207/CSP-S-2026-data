#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,a[N],b[N],ans=0;char c1[N],c2[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;for(int i=1;i<=n;i++){cin>>a[i]>>c1[i];}for(int i=1;i<=n;i++){b[i]=a[n-i+1];c2[i]=c1[n-i+1];}
	for(int i=1;i<=n;i++){a[i]+=a[i-1];}for(int i=1;i<=n;i++){b[i]+=b[i-1];}
	int r=0;
	for(int i=1;i<=n;i++){
		while(r<a[i]){
			int nxt=upper_bound(b+1,b+n+1,r)-b,nxt_r=min(a[i],b[nxt]);
			if(c2[nxt]!=c1[i]){ans+=(nxt_r-r);}r=nxt_r;
		}
	}
	cout<<ans/2;
	return 0;
}