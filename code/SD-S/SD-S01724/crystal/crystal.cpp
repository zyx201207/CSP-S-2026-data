#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename T>void read(T &x){int f=1;char ch=getchar();x=0;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}x=x*f;return;}

const int N=5e5+5;
int n,m,ans;
int a[N],pre[N];

bool ck(int x){
	for(int i=x;i<=n;i++)
		if(x*a[i]-(pre[i-1]-pre[i-x-1])<=m)return 1;
	return 0;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;i++)read(a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	int l=1,r=1e6+5,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(ck(mid))l=mid+1;
		else r=mid-1;
	}
	cout<<l;
}
