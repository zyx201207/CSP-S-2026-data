#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,T;
int n,d;
int x[2000010],f[2000010],g[2000010];
int find(int a){
	int l=a,r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(x[mid]-x[a]>d)r=mid-1;
		else l=mid;
	}
	return l;
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	int pd=1;
	for(int i=1;i<n;i++){
		if(x[i+1]-x[i]!=x[2]-x[1]){
			pd=0;break;
		}
	}
	if(C==13||C==14){
//	if(find(find(1))>=n){
		int ans=0;
		for(int i=1;i<=n;i++){
			int j=find(i);
			if(j-2<i)continue;
			int rb=find(j-1),ra=find(j-2);
			ans+=rb-ra;
		}
//		cerr<<"---"<<endl;
		cout<<ans<<endl;
		return;
	}
	if(C==11||C==12){
//		cout<<"---"<<endl;
		int k=x[2]-x[1];
		int t=d/k;
//		cout<<k<<' '<<d<<endl;
		if(t<2){
			cout<<0<<endl;
			return;
		}
//		cout<<t<<endl;
		int ans=0;
		for(int i=1;i<=n;i++)ans+=(i>=t*2);
		cout<<ans<<endl;
		return;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		f[i]=0,g[i]=1;
		int l=i,r=i,sum=1;
		for(int j=i+1;j<=n;j++){
			while(x[j]-x[l]>d)sum-=g[l],l++;
//			cout<<"--- "<<l<<' '<<r<<" "<<sum<<endl;
			if(l==j)break;
			for(int k=r;k<l;k++)sum+=g[k+1];
			r=max(l,r);
			while(r<j-1&&f[r+1]==f[l])r++,sum+=g[r];
			f[j]=f[l]+1;g[j]=sum;
//			cout<<i<<' '<<j<<' '<<f[j]<<' '<<g[j]<<endl;
//			cout<<l<<' '<<r<<" "<<sum<<endl;
			if(g[j]==2)ans++;
		}
	}
	cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
//    freopen("migrate4.in","r",stdin);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>C>>T;
    while(T--){
    	solve();
	}
	
    return 0;
}
/*
去你的岛... 
//维护最短路，次短路，和第三短路 
不对，这道题应该不是图论，上一道是图论了 
这个应该是 dp 还有计数 

15:23
难道郭总说这次考试简单是真的吗？T1 T2 做完了 
嗯这道题很像调 dp 的时候的一些东西啊... 
应该是 dp 优化 
比如先写出朴素的 dp 
f[i][j] 表示 i 到 j 的最短路长度，g[i][j] 表示 i 到 j 的最短路长度是否为 1 
转移就是暴力转移了 f[i][j] = min f[i][k] (x[j]-x[k]<=d)
还需要线段树？40 分 

嗯我觉得这道题有一些单调性 
比如 i,j 有两种最短路，经过 i,j 的也一定有了 
那有没有这种包含关系？ 
确实没有 

先看看特殊性质 
A 的话应该是好做的，但是是一个计数问题 

4:08 吸完氧回来 
首先呢，最短的路径一定是每次走最远 
然后第二短就是又一次走了次远，然后后面追平 
但是题目中是恰好两条 
反正暴力可以对于每一个点为起点来一遍 
g[i] 表示走到 i，最短的路径的条数，f 是长度 
这个状态看起来就很冗余，还需要数据结构维护 
哦，我们发现这个东西有单调性 
可以用单调队列维护 

嗯，如果起点变了呢 
不好维护呢 
算了，先写暴力找灵感 

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

for(int i=1;i<=n;i++){
	f[i]=0,g[i]=1;
	int l=i,r=i,sum=1;
	for(int j=i+1;j<=n;j++){
		while(x[j]-x[l]>d)sum-=g[l],l++;
		if(l==j)break;
		for(int k=r;k<l;k++)sum+=g[k+1];
		r=max(l,r);
		while(r<j-1&&f[r+1]==f[l])r++,sum+=g[r];
		f[j]=f[l]+1;g[j]=sum;
		if(g[j]==2)ans++;
	}
}


会不会就不是这个思路 
比如线段树优化建图 

直接暴力转化问题 
求出一个序列，序列方案数？ 


找找性质？ 

或者接着刚刚的，我们枚举 i，能不能算出之前有多少 j 
或者刚才的东西能不能用线段树维护 

有一个性质，海鸟不可能分叉两次 
有没有性质，就是不同的分叉不可能交叉 
没有 
然后再排除掉多分叉 


算了，先写性质 A 
int k=x[2]-x[1];
int t=d/k;
if(t<2){
	cout<<0<<endl;
	return;
}
int ans=0;
for(int i=1;i<=n;i++)ans+=(i>=t*2);
cout<<ans<<endl;
感觉很有启发？ 
这种情况是当且仅当，最大值，然后有退让 
还是做不了，看性质 B 

那么这个性质中，距离 <=2，对于比较远的两个点，需要看有几个点是他们共同连接的 
距离比较近的，就是有直接连边的就肯定没有答案了 

那么对于每个点 i 
找到能到达最远的 j，保证 j 一定能到之后的任意 
然后只需要找到 j-1 能到，j-2 到不了的就行了 

也十分有提示性 
但可惜没有大样例 
不过先写吧 


13 1
10 11
1 2 3 5 7 11 13 15 16 19


*/