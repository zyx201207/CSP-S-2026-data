#include<bits/stdc++.h>
using namespace std;
/*
现在是18:09 考试还有半个小时结束 我第一题写的二分感觉没问题，第二题骗了三十分...?但愿能骗到这么多，三题深搜 四题写了个滚木
感觉第一题还行... 至少写出来二分了不是吗？一开始想写贪心，后来突然想到了二分 我觉得如果数据不爆long long的话应该是能过的
第二题...这个东西特殊性质不特殊，跑最短路只能拿三十分...随便吧，至少有分
嗯，4个小时过得还挺快的其实 今年就快要结束了，希望能拿到一等（（（
如果你看到这里的话，应该已经可以知道自己成绩了（luogu真是太好用了你知道吗）,请问我考得怎么样呀^-^
最后的最后，一道二分三道图论啥意思啊！！！说好的字符串动规组合数呢！！！（其实T3像组合数，但是我不会…~） S
*/
long long n,m;
long long a[500005],f[500005],l,r,ans;
bool solve(long long res){
	for(long long i=res;i<=n;i++){
		long long v=f[i]-f[i-res]+a[i-res];
		long long u=res*a[i]-v;
		if(u<=m){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		f[i]=f[i-1]+a[i];
	}
	r=n;
	while(l<=r){
		long long mid=(l+r)/2;
		if(solve(mid)){
			ans=mid;
			l=mid+1;
			
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
/*
5 5
  1  2  4  8  9
0  1   3  7   8//a[i]-a[1]
0  1   4  11  
0  1   2  4   1 
            res*b[n]-(b[n-1]+b[n-2]...+b[n-res])
*/
/*
下面为神秘大贪心 
//struct node{
//	long long row;
//	long long ch;
//	long long num;
//}res[500005];
//long long cnt=0;
//struct Node{
//	long long cos;//花费能量大小
//	long long num//合并后人数
//	long long cn;//要更新的里面较小的在第几个
//	long long ma;//row较大值的大小 
//	bool operator <(const Node p) const{
//	}
//};m 
//priority_queue<Node> q;
//	for(long long i=1;i<=n;i++){
//		res[++cnt]={cnt,a[i]-a[1],1};
////		<<res[cnt].row<<res[cnt].ch<<res[cnt].num<<endl;
//	}
//	fro(long long i=1;i<cnt;i++){
//		
//	}
*/

