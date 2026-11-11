#include<bits/stdc++.h>
#define int long long
#define mid ((l+r)>>1) 
#define fi first
#define se second
using namespace std;
const int N=1e6+5;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,a[N],s[N];
void sl(){
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i-1,mx=0;
		while(l<=r){
			if(a[i]*(i-mid)-(s[i-1]-s[mid-1])<=m){
				mx=i-mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		ans=max(ans,mx+1);
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int t=1;
//	t=read();
	while(t--)sl();
	return 0;
} 
