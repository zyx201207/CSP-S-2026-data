#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return x*f;
}
const int N=500005;
int n,m,a[N],sum[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+(a[i]-a[i-1])*(i-1); 
	for(int i=1;i<=n;i++){
		int l=i,r=n,pos=l;
		while(l<=r){
			int mid=(l+r)>>1;
			if(sum[mid]-(a[mid]-a[i])*(i-1)-sum[i]>m) r=mid-1;
			else l=mid+1,pos=mid;
		}
		ans=max(ans,pos-i+1);
	}
	cout<<ans;
	return 0;
}
/*
14:36 写完了
14:38 发现做法假了
14:46 重新写完了
14:52 调不出来，写T2 
15:33 写完T2立刻调出来了
18:29 我甚至pos初始化为r过了所有大样例，检查出来了 
*/
