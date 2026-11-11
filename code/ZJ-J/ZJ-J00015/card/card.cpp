#include<bits/stdc++.h>
#define int long long
#define INF 1145141919810
using namespace std;
int n,m,a[620001];
int pns[320001],llst[320001];
int gid[320001];//id=i.what is the num?
struct sweeter{//of m
	int id,pn,lst,ret,pls;
}p[320001];
bool cmp(sweeter x,sweeter y){
	return x.lst<y.lst;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[a[i]].id=a[i];
		p[a[i]].pn++;
		p[a[i]].lst=max(p[a[i]].lst,i);
	}
	for(int i=1;i<=m;i++)
		p[i].pls=p[i].pn;
	sort(p+1,p+m+1,cmp);
	for(int i=1;i<=m;i++)
		gid[p[i].id]=i;
	for(int i=1;i<=m;i++){
		if(i<m){
			int now=p[i].lst;
			now++;
			now=gid[a[now]];
			p[i].ret=now;
			p[now].pls+=p[i].pls;
		}
		pns[p[i].id]=p[i].pls;
	}
	for(int i=1;i<=m;i++)
		cout<<pns[i]<<" ";
	return 0;
}
/*
我不知道我拿了多少分
我只知道我去年就 AFO 了
但是因为某种原因还是在这里写东西
这可能（大概率）就是最后一次了
看起来是只能拿 0pts 离场了
路上三年
我从来没学会过怎么测大样例
我直到今天还是使用瞪眼法草草看两眼了事
或许有 bug 但那已经不再重要
好好迎接我的最后零年
又有多少人能看到这个呢
奋斗一生 终是一瞬
走时 1= 回时爆零

by luogu 1328469

还有一句
老师说场上不要吃太多 C
于是我今年只带了大概 1kg 的美食
真香
比零分还香
有无有心之人给我看看这代码到底多少
欢迎私信我
*/