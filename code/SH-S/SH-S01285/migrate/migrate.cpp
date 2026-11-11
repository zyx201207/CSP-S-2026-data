// Think TWICE
// Code ONCE
// NEVER FORGET YOUR 143pts IN NOIP 2025

/*
题意是要求双径岛屿对计数。正解时间复杂度应该是要求线性。
注意到性质，一个双径岛屿对把它左右多余部分砍掉，必然是这个形式：
x -> m1 -> y
x -> m2 -> y

而且只能是这个形式吧ww
我可以先贪心地向后寻找岛屿。如果可以飞到的岛屿数量==2，那么我这里可能可以贡献双径岛屿对了。
而且其实那个一定走长度最短的限制可能可以忽略。
因为比如我不走长度最短，我就会有不止一种走法可以完成这个东西，也不会计入统计了。
现在变成寻找刚刚提到的那个性质的对数了。
这个东西，我还必须是连续的四个岛屿吧。不然中间又有也不行。
一个双径岛屿对，如果左右拓展都不会构成新路径就可以把拓展的也计数了嗯嗯。 
会有重叠吗？会的。 
我先写一版code看看。
比如，说 (1,4) 满足，(2,5)满足，(4,7) 满足，这种情况我想想看。
记住原则：仅能包进去一个双径岛屿对。
(1,4) (2,5) (2,6) (4,7) 

发现个hack（来自样例3）
0 1
6 12
-10 -6 -2 2 6 10
考虑一整个，最优质的走法是-10 -> 2 -> 10
或者-10 -> -2 -> 10
都能取到12，且只有2个方案。
推翻了刚刚的猜测ww，双径岛屿对的len可以>4呢
怎么办呢……
考虑一个事情，这个是从第一个比他大的那里开始算呢……
就是刚刚那个修正一下，满足的还是一个 x -> m1 -> m2 -> y 的模型
但是要求：
x不可以直接到y； 
x -> m2 是x可以走出的最远 （不然x -> m3 -> y也可以啊ww）
m1 -> y 是y向左可以走出的最远（同上原因）
m1 m2相邻，m1<m2
这个东西咋办？
呃 向左向右最远可以线性处理，这个pair是不是也可以线性处理好来着。然后条件还是一样的，只能包含一个双径岛屿对，不能有第二个，吧？ 
但比如这样的数据
-10 -9 -6 -2 2 6 9 10
取d=12
ans应该是4
这……
也就是说，我固定m1 m2是啥
左右动x y是可以的。
这一坨双径岛屿对里不含其他的就可以吧。
那我拿最内部的计数就可以吧。 
努力让left最大，right最小。这样记录成一个pair
17:32 还要考虑可达性。 
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define up(l,r,i) for(int i=(l);i<=(int)(r);++i)
#define pb emplace_back
#define left hughpigissocuteqwq
#define right mayiperformwellinnoip2026

void file(string fl){
	freopen((fl+".in").c_str(),"r",stdin);
	freopen((fl+".out").c_str(),"w",stdout);
}

ll ksm(ll a,ll b,ll p){
	ll ret=1%p;
	while(b){
		if(b&1)ret=ret*a%p;
		a=a*a%p;
	}
	return ret;
}

constexpr int N=2e6+7;
constexpr ll INF=1e18;

ll n,m,a[N],ans,left[N],right[N],acl[N],acr[N];
vector<pair<ll,ll> > pos;

void solve(){
	cin>>n>>m;ans=0;
	up(1,n,i)cin>>a[i],left[i]=right[i]=-1,acl[i]=acr[i]=i;//题目保证a有序
	up(2,n,i)if(a[i]-a[i-1]<=m)acl[i]=acl[i-1];
	for(int i=n-1;i;--i)if(a[i+1]-a[i]<=m)acr[i]=acr[i+1];
	ll qwq=1;
	up(1,n,i){
		while(qwq<=n&&a[qwq]-a[i]<=m)++qwq;
		right[i]=qwq-1;
	}
	qwq=n;
	for(int i=n;i;--i){
		while(qwq&&a[i]-a[qwq]<=m)--qwq;
		left[i]=qwq+1;
	}
//	up(1,n,i)cout<<left[i]<<' '<<right[i]<<'\n';cout<<'\n';
	pos.clear();//要让left最大，right最小。两数组都递增 
	ll posl=1,posr=1;
	while(posl<=n){
		while(right[posr]<=left[posl])++posr;
		while(right[posr+1]==right[posr]&&posr<=n)++posr;//posr最大化
//		cout<<"posl="<<posl<<" posr="<<posr<<'\n'; 
		if(posr>n)break;
		if(left[posl]==right[posr]-1&&posr<posl&&left[posr]<left[posl]&&left[posl]<right[posr]&&right[posr]<right[posl]&&posl-posr>1){
			if(posl==1||left[posl-1]!=left[posl]){//posl尽可能小 
				pos.pb(make_pair(posr,posl));
				++posr;
			}
		}
		++posl;
	}
	if(pos.empty()){
		cout<<"0\n";
		return;
	}
//	for(auto x:pos)cout<<x.first<<' '<<x.second<<'\n';
//	ll prel=0;
//	for(int i=0;i<(int)pos.size();++i){
//		ll l=pos[i]-prel;
//		ll r=0;
//		if(i==(int)pos.size()-1)r=n-(i+3)+1;
//		else r=pos[i+1]-pos[i];
//		ans+=l*r;
//		prel=l;
//	}
//	cout<<ans<<'\n';
	if(pos.size()==1){
		cout<<acl[pos[0].first]*(acr[pos[0].second]-pos[0].second+1)<<'\n';
		return;
	}
	for(int i=0;i<(int)pos.size();++i){
		ll l=pos[i].first,r=pos[i].second;
		if(i==0){
			ans+=acl[l]*(min(pos[i+1].second,acr[r]+1)-r);
//			cout<<acl[l]*(min(pos[i+1].second,acr[r]+1)-r)<<'\n';
		}
		else if(i==(int)pos.size()-1){
			ans+=(l-max(pos[i-1].first,acl[l]-1))*(acr[pos[(int)pos.size()-1].second]-pos[(int)pos.size()-1].second+1);
//			cout<<(l-max(pos[i-1].first,acl[l]-1))*(acr[pos[(int)pos.size()-1].second]-pos[(int)pos.size()-1].second+1)<<'\n';
		}
		else ans+=(l-max(pos[i-1].first,acl[l]-1))*(min(pos[i+1].second,acr[r]+1)-r);
	}
	cout<<ans<<'\n';
}

int main(){
	file("migrate");
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,T=1;
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}
/*
0 1
5 2
1 2 3 4 5

0 1
8 3
0 1 2 4 8 10 11 13

0 1
8 12
-10 -9 -6 -2 2 6 9 10
1 5
1 5 这里 
1 6
1 8
1 8
3 8
4 8 这里 
4 8
*/ 
