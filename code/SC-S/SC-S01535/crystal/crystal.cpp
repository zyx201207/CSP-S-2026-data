#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
using ll=long long;
ll a[maxn],dis[maxn];//原数组 差分数组
ll lop[maxn];//以该点为左端点的最大值
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	ll n,m;cin>>n>>m;//读入
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);//为了得到最值采用小到大排序
	for(ll i=2;i<n;i++) dis[i-1]=a[i]-a[i-1];//构造差分
	for(int i=2;i<=n;i++){
		int cnt=0;
		int sum=m;//剩余可分配长度
		for(int j=i;j>=1;j--){//由右往左找最值（连续）
			if(sum>dis[j]+cnt){
				cnt+=dis[j];
				sum-=cnt;//规划剩余
				lop[i]++;//该右端点存在rp++
			}
			else break;
		}
	}
	sort(lop+1,lop+1+n);//输出最大答案
	cout<<lop[n];
	return 0;
}/*
分析：题面让每次让小的数往大变所以构造差分利用贪心
时间复杂度:O(2n+n^2) Perhaps可以通过此题但因端点查询本题可以
考虑动态规划dp但动规数组过大
*/
//唉CCF对不起了，我真的是无能为力，我才明白我10天的预习只是表面工作我就没有真正读懂过
//我只会分辨哪道题是什么类型，但对于实践我觉得还是需要沉淀
//明年再见吧，希望我J组前三题全过，CCF，明年再见
//第一题是线段树，第二题是floyed第三题是djstra第四题是状压dp