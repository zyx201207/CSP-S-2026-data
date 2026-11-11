#include<bits/stdc++.h>
using ll=long long;
using namespace std;

inline ll read() {
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
} 

inline int print(int x) {
	if(x<0) putchar('-'),x=-x;
	if(x>9) print(x/10);
	putchar(x%10+'0');
}

const int N=5e5+5;
int n,ans;
ll arr[N],sum[N],m;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) arr[i]=read();
	sort(arr+1,arr+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+arr[i];
	for(int i=1;i<=n;i++) {
		int l=1,r=i-1;
		while(l<r) {
			int mid=(l+r)>>1;
			if(arr[i]*(i-mid)-(sum[i-1]-sum[mid-1])<=m) r=mid;
			else l=mid+1;
		}
		if(i-l+1>ans) ans=i-l+1;
	}
	print(ans);
	return 0;
}
