#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=5e5+5;
const int N=505;
ll c,m,n,d,q;
ll w[M],k[N],a[N][N*2],t[N][N*2],x,y;
vector<pair<ll,ll> >g[M];
ll ans;
//对于这道题，我们可以dfs暴力搜索
//首先设置参数x,fa,ex,line,sum
//不难看出x是当前节点，fa是上一个节点，ex是结束节点，line表示的是当前在几号线上，sum表示当前所花的资金
//那我们如何知道当前节点在几号线上呢，这个时候注意到32%的数据可以支持
//不不不！我们可以在输入时，用vecotr存储出当前的线路！！只是多一个参数罢了 
//那我们就可以无穷的枚举下一个出发点，通过vector数组来给我们存储 
//当我们到达结束节点位置时，就return，并更新当前答案
//找下一个节点时，循环vecotr数组找下一个节点，等于fa就continue
//每次往下dfs的时候就加上 
//只是记录一些思路喵~~~ 
//只是好像WA+RE了呢~~~ 
//今天S组好难呀（我是个蒟蒻我当然觉得难了，但是T1,T2暴力这么好打有点过分了吧
//今天晚上怎么奖励自己呢？算了，J组考成那样子，我看今晚是要吃皮带炒肉丝了吧
//也就最后这个时候10分钟，T3,T4部分分想不出来，所以自然就摆烂了
//本来S组就不是我的目标，但是我J组大那么差，冯91打的都比我好，有点自卑了，诶~~~~
//还剩最后9分钟，我也不想打什么了，随便打点文字放松放松吧！
//但是看别人拿了一等就是很嫉妒呀，哎
//不知道回去以后，看到班里人基本上都拿一等，就我拿了二等，他肯定很失望吧 
void dfs(ll x,ll fa,ll ex,ll line,ll sum){
	if(x==ex){
		sum+=w[ex];
		ans=min(ans,sum);
		return ;
	}
	for(auto it:g[x]){
		ll nx=it.first;
		ll nline=it.second;
		ll nt,nt_2;
//		cout<<nx<<' '; 
		if(nx==fa) continue;
		for(ll i=1;i<=k[nline];++i){
			if(a[nline][i]==nx){
				nt=t[nline][i];
				break;
			}
		}
		for(ll i=1;i<=k[line];++i){
			if(a[line][i]==nx){
				nt_2=t[line][i];
				break;
			}
		}
		if(nline==line){
			dfs(nx,x,ex,nline,sum+nt);
		}
		else{
//			cout<<'x'<<' ';
//			cout<<nt<<' '<<nt_2<<'\n';
			dfs(nx,x,ex,nline,sum+nt_2+nt);
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];++j){
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=2;j<=k[i];++j){
			g[a[i][j]].push_back({a[i][j-1],i});
			g[a[i][j-1]].push_back({a[i][j],i});
		}
	}
	while(q--){
		ans=1e18;
		cin>>x>>y;
		ll tt,line;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=k[i];++j){
				if(a[i][j]==x){
					tt=t[i][j];
					line=i;
					break;
				}
			}
		} 
		dfs(x,0,y,line,w[x]+tt);
		cout<<ans<<'\n';
	}
	return 0;
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
}
