#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0;
	int f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
const int N=5e5+100;
int a[N];
int n;
int pre[N];
int m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	reverse(a+1,a+1+n);
	int ans=0;
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=i;
		int r=n;
		int as=-1;
		while(l<=r){
			int mid=(l+r)>>1;
			int Sum=pre[mid]-pre[i];
			int len=mid-i;
			if(len*a[i]-Sum<=m)as=mid,l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,as-i+1);
	}
	cout<<ans<<"\n";
	return 0;
}
