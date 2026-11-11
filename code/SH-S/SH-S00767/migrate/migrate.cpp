//最后开T3
//梳理思路：目前还剩一个半小时，225pts，前面正确性没问题。T4剩下15pts可以打。暂时决定全力冲T3。
//读题。
//吃巧克力。
//首先，u->v的最短路径绝对不可能出头。显然。
//更进一步地， 绝对不可能回头。显然。
//那么可以考虑dp。f[x][i]表示x到i的最短路，g[x][i]表示方案数。
//f[x][i]=min(f[x][j]+1),a[j]+d<a[i];g[x][i]=sum(g[x][j]),f[j]==f[i]-1。j可以用双指针。 
//外层x:1->n,内层i和j:1->n。则n^2,40pts。
//接下来看特殊性质
//A:若点i最多可以飞到i+2，那么>1的奇数可以，偶数不行。
//若点i最多可以飞到i+3，那么>2的%3==2可以
//若i+4，那么>3的%4==3可以。以此类推。8pts。 
//B:没思路
//C:没思路
//开始编码 
//不对。A想错了。应该是只有2tmp-1才合法。没事小问题。
//改完了。过样例。
//目前263pts。去厕所，然后检验。 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2000005;
int c,t,n,d,a[N],gc,tmp,ans;
int f[N],g[N],cnt[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;++i) cin>>a[i];
		ans=0;
		if(c==11||c==12){
			gc=a[2]-a[1]; tmp=d/gc;  //tmp能跳几格
			if(tmp==0||tmp==1){
				cout<<"0\n"; continue;
			}  
			ans=max(0ll,n+1-2*tmp); 
			cout<<ans<<"\n";
		}
		else{
			for(int x=1;x<=n;++x){
				for(int i=0;i<=n;++i) f[i]=1e18,g[i]=0,cnt[i]=0;
				f[x]=0; g[x]=1; cnt[0]=1;
				int i=x+1,j=x,sum=1;
				for(;i<=n;++i){
					while(a[i]-a[j]>d){
						sum-=g[j]; cnt[f[j]]-=g[j]; ++j;
					}
					if(i==j) break;
					f[i]=f[j]+1;
					g[i]=cnt[f[j]];
					cnt[f[i]]+=g[i];
					if(g[i]==2) ans++;
				}
			}
			cout<<ans<<"\n";
		} 
	}
	return 0;
}
