#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

const int N=5e5+5;

int n,m;
int a[N],sum[N];

inline void getmx(int &a,int b){
	return a=(a>b?a:b),void();
}

inline int qry(int l,int r){
	return sum[r]-sum[l-1];
}

inline bool chk(int k,int pos){
	return k*a[pos]-qry(pos-k,pos-1)<=m;
}

signed main(){
//	freopen("crystal4.in","r",stdin),freopen("out.txt","w",stdout);
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)sum[i]=sum[i-1]+a[i];
	int res=1;
	for(int pos=1;pos<=n;++pos){
		int l=1,r=pos-1,tmp=-1;
		while(l<=r){
			int mid=(l+r+1)>>1;
			if(chk(mid,pos))tmp=mid,l=mid+1;
			else r=mid-1;
		}
		getmx(res,tmp+1);
	}
	return cout<<res<<"\n",0;
}

/*

5 5
1 2 4 8 9

3

*/

/*

5 8
-3 -1 2 2 7

4

*/

/*

也就是，通过至多 m 次 +1 操作，能够让多少个数相等
先排序，每个点只能往右靠
贪心地，是不是留一个点不动，其他点往这个点上靠
枚举一下靠上去的这个数是哪个，这个是 O(n) 的
然后怎么找能靠上去的点数
考虑二分，要找的就是前若干个点到当前点的距离和
假如说找前面 k 个点，那就是 (a_{pos}-a_{pos-k})+(a_{pos}-a_{pos-k+1})+...+(a_{pos}-a_{pos-1})
那就是 k·a_{pos}-Σa_{pos-k~pos-1}
前缀和一下，没了啊
这就是 jmr 看 T4 的感觉吗

*/