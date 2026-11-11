#include<bits/stdc++.h>
#define int long long
#define fr first
#define sc second
#define ls(p) (p<<1)
#define rs(p) ((p<<1)|1)

using namespace std;
typedef pair<int,int> pii;
int const N=5e5+5;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int n,m,cnt,ans;
int a[N],pre[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	pre[0]=0;
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	ans=1;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)>>1ll;
			if(a[i]*(i-mid+1)-(pre[i]-pre[mid-1])<=m){
				ans=max(ans,i-mid+1);
				r=mid-1;
			}
			else l=mid+1;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
/*
枚举一个水晶 使它不动 然后贪心考虑比它小的
 
*/ 

