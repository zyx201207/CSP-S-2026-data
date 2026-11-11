#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+5;
int c,t,n;
long long x[maxn],d;
int q[maxn],dt,dw,l[maxn],r[maxn];
long long ans;
int dis[400],sl[400];
void d1(){
	for(int iii=1;iii<=n;iii++){
		for(int i=1;i<=n;i++){
			dis[i]=maxn;
			sl[i]=0;
		}
		dis[iii]=0,sl[iii]=1;
		for(int j=iii;j<=n;j++){
			for(int k=j+1;k<=r[j];k++){
				if(dis[k]>dis[j]+1){
					dis[k]=dis[j]+1;
					sl[k]=sl[j];
				}
				else if(dis[k]==dis[j]+1){sl[k]+=sl[j];}
				sl[k]=min(sl[k],3ll);
			}
			ans+=(sl[j]==2);
		}
	}
	cout<<ans<<'\n';
}
void dA(){
	int k=r[1]-1;
	if(k<=1){
		cout<<"0\n";
		return; 
	}
	cout<<max(0ll,n-k-k+1)<<"\n";
}
void dB(){
	static int sl1[maxn],sl2[maxn];
	for(int i=1;i<=n;i++){sl1[i]=sl2[i]=0;}
	for(int i=1;i<=n;i++){
		if(r[i]!=i+1&&r[i]!=i){sl1[r[i]]++;}
		if(l[i]!=i&&l[i]!=i-1){sl2[l[i]]++;}
	}
	for(int i=1;i<=n;i++){
//		cout<<i<<" "<<l[i]<<' '<<r[i]<<' '<<sl1[i]<<" "<<sl2[i]<<" ??? i l r sl1 sl2\n";
	ans+=1ll*sl1[i]*sl2[i-1];} 
	cout<<ans<<"\n";
}
void dd(){
	cin>>n>>d;
	ans=0;
	dt=1,dw=0;
	bool pd1=1;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		r[i]=n;
		while(dw-dt+1&&x[q[dt]]+d<x[i]){r[q[dt++]]=i-1;}
		q[++dw]=i;
	}
	for(int i=1;i<n;i++){pd1=pd1&(x[i+1]-x[i]==x[2]-x[1]);}
	if(c==11||c==12){
		dA();
		return;
	}
	dt=1,dw=0;
	for(int i=n;i>=1;i--){
		l[i]=1;
		while(dw-dt+1&&x[i]+d<x[q[dt]]){l[q[dt++]]=i+1;}
		q[++dw]=i;
	}
	if(c==13||c==14){
		dB();
		return;
	}
	d1();
}
signed main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){dd();}
	return 0;
}
/*
思路（预计思考到16:10 40min） 
预估得分32 


0 1
6 3
1 2 3 4 5 6

0 1
6 15
5 10 15 20 25 30




1.u到v的最短路一定是每次选择能选的最大的点（或直接到终点） ，可以对于每个点暴力求出来他能到的最远的点 ，以这个点为他的父亲建树
2.思考恰好两条的性质， 一定是u到v（u<v）的路径上只有一个分界点（一边走a一边走b）不同，其余点全部相同时才可以产生贡献
3.我父亲的前面的兄弟我也可以一步跳到，且这个不影响最短路的距离，
所以如果(u,v)(u<v)可以产生贡献则一定是u往上走到v/v的后面的兄弟的路径上恰好只有一个节点存在两个孩子 （不含u,v/v后面的兄弟） 
，我还可以一步跳到我后面的兄弟上 
4.考虑枚举分那个有两个孩子的节点x，并求出以其为根网下走不经过 任何一个孩子数量超过二的节点 的可经过节点数（含自己） A[x]
5.并求出以其往上走 不经过任何一个孩子数量超过二的节点 的路径上的所有节点的数量（不含x,即路径长度,不可以跳到0） 设其为B[x] 
如果最终往上跳到极限的那个点存在兄弟，则B[X]还要加上前面的兄弟数 
6.答案为A[x]*B[x]的和 
7.最终可能为森林
8.这样算出来的答案是不全的，我还要考虑以一个点恰有两种跳到目标点前面的兄弟的数量，答案由第二个点的孩子计算 ，答案为A[son2]*后面的兄弟数 

















1.n<=5000可以直接暴力枚举每个点作为起点开始dp，记录最短路长度和距离	O(n*n)  40分 
3.先考虑特殊性质A 等差意味着所有点i最多只能跳到i+k,此时u到v(u<v)的最短路为(v-u)/k向上取整
只有(i,i+k+k-1)才能产生贡献 
4.考虑特殊性质B，既然存在一座岛屿可以直接跳到别的岛屿xn-x1<=2d,于是一个点到另一个点的距离上限为2，
发现只有距离为2的点对才有可能产生贡献 ，当且仅当在i<j<k且xj-xi<=d xk-xj<=d的j数恰好为2时产生贡献，
即二者覆盖范围恰好只重叠了2个时会产生贡献 

0 1
4 2
1 2 3 4

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
10 222222222222222208
-999999999999999936 -777777777777777728 -555555555555555520 -333333333333333312 -111111111111111104 111111111111111104 333333333333333312 555555555555555520 777777777777777728 999999999999999936
*/
