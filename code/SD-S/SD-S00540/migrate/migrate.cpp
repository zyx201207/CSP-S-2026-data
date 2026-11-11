#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long x[N],f[N],g[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--){
		long long n,d,ans=0;
		cin>>n>>d;
		x[0]=-1e18-10;
		for(int i=1;i<=n;i++) cin>>x[i];
		//edge 
		for(int i=n;i>=1;i--){
//			cout<<ans<<" ";
			int p=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
//			cout<<i<<" "<<p<<"\n";
			if(p==i) continue;
			int lst=p-1;
			int p1=upper_bound(x+1,x+n+1,x[lst]+d)-x-1;
			int lstlst=p-2;
			int p2=upper_bound(x+1,x+n+1,x[lstlst]+d)-x-1;
//			cout<<p2<<" ";
//			if(i==3) cout<<p1<<" "<<p2<<"***";
			if(p2>p) continue; 
			if(p1>p) ans+=f[p],g[i]=f[p];
			else ans+=g[p],g[i]=g[p];
//			if(i==1) cout<<f[p]<<"&&&";
//			if(i==1) cout<<f[p]<<" "<<g[p]<<" ***";
//			cout<<i<<" "<<ans<<"***\n";
//			if(i==1) cout<<ans<<"&&&";
			int pf=upper_bound(x+1,x+n+1,x[i-1]+d)-x-1;
//			cout<<pf<<" ";
			if(p1>p) f[i]=f[p]+pf-i;
			else f[i]=pf-i+g[p];//后面只有下链最优 
		}
//		cout<<"\n";
//		for(int i=1;i<=n;i++){
//			cout<<f[i]<<" ";
//		}
//		cout<<"\n";
//		for(int i=1;i<=n;i++) cout<<g[i]<<" ";
//		cout<<"\n"; 
//		cout<<f[4]<<" ";
		cout<<ans<<"\n";
		for(int i=0;i<=n;i++) f[i]=g[i]=0;
	}
	return 0;
}
/*
不难看出固定左端点判断方式：
二分找到极长延伸右端点，最多只有其左一个可以超出这个点，否则不合法，只需维护前缀min，由于单调不需数据结构 
从右往左扫描左端点，只有两种情况，分别记为f,g，表示超出/恰好不超出
递推即可
**易证，p2>i，后面都不合法！ 
f,g求法：
特别地，若上链跨一步重合，后面必定不优，所以总是前一个点，这个点构成f（超出）
g可转为f求 
*/
