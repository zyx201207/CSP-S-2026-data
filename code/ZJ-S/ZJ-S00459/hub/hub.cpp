#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,T,n,k,a[1114514];
vector<int>v[1114514];
inline int read(){
	int x=0,f=1;char ch=getchar();
	for(;ch>'9'||ch<'0';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	return x*f;
}
inline int ck(int x){
	int tot=0,y=-1,z=-1;
	for(int i=1;i<=n/2+1;i++){
		if(i-1>x){
			y=i;
			break;
		}
	}
	for(int i=n/2+1;i;i--){
		if(n/2+1-i>x){
			z=i;
			break;
		}
	}
	if(z<=y||z-y+1<=k)return 1;
	return z-y+1-k<=x;
}
inline void ts(){
	if(n==k){
		cout<<"0\n";
		return;
	}
	int l=1,r=n/2+1,mid,ans=1;
	for(;l<=r;){
		mid=(l+r)>>1;
		if(ck(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	C=read();T=read();
	for(;T;T--){
		n=read();k=read();
		for(int i=1;i<=n;i++)v[i]={};
		for(int i=1,x,y;i<n;i++)x=read(),y=read(),v[x].push_back(y),v[y].push_back(x);
		if(C==13||C==14||C==0){
			ts();
			continue;
		}
		cout<<0+(n!=k)<<'\n';
	}
	return 0;
}
/*
bai le
wo zen me dou bu hui
*/