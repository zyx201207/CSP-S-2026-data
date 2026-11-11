//袁浩文 西安辅轮中学 SN-J00625 
#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define elif else if
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(x) (x&-x)
#define setdigit(x) cout<<fixed<<precision(x)
#define debug(...) fprintf(stderr,##__VA_ARGS__)
using namespace std;
/*
这是贪吗
完了今年不会AK不了了吧
完了该退役了
multiset删除的复杂度是多少
从高到低按位贪
如果第一次出现这一位为1的数的个数>m就放进c里
如果等于m那么就选这m个因为选其他的都只可能是小位大
后面如果有>m的排除掉没有在c里出现的，剩下的如果=m直接就这几个，如果>m对应的数++
如果到最后都没有出现那么排序出现的次数选前m个
不够m格输出0
所以我需要一个能随机访问快速查找的东西
这有啥
完了我忘了
算了用vector和lower_bound代替一下吧
完了11:15了我连T3都没做出来
我find没判是不是没找到
但是问题是我是在x.se==1的时候才find的啊
我chovy今年不能是个J二等吧
我常常追忆过去
生命瞬间定格在脑海
诶不是我往b里放的什么东西
还是挂的啊
啊啊啊啊啊
算了去打T4暴力了
完了
全完了
*/
const int maxn=2e5+5;
int a[maxn],n,m;
vector<pii>b[32],e;
vector<int>c,d;
int find(int x){return lower_bound(c.begin(),c.end(),x)-c.begin();}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=30;i>=0;i--)for(int j=1;j<=n;j++)if(a[j]>>i&1)b[i].push_back({a[j],-1});
	int f=0;
	for(int i=30;i>=0;i--){
		int sz=b[i].size();
		if(sz==m){
			if(f==0){//第一次刚好m个
				int ans=-1;
				for(pii x:b[i]){
					if(ans==-1)ans=x.fi;
					else ans&=x.fi;
				}
				cout<<ans;
				return;
			}else{
				int cnt=sz;
				for(int j=0;j<b[i].size();j++){
					int id=find(b[i][j].fi);
					if(id!=c.size()&&c[id]==b[i][j].fi)b[i][j].se=1;//出现在c里
					else b[i][j].se=0,cnt--;
				}
				if(cnt==m){//出现了m个
					int ans=-1;
					for(pii x:b[i]){
						if(x.se==1){
							if(ans==-1)ans=x.fi;
							else ans&=x.fi;
						}
					}
					cout<<ans;
					return;
				}else {for(int j=0;j<b[i].size();j++)if(b[i][j].se==1)d[find(b[i][j].fi)]++;}//不够m个往c里计数 nlogn
			}
		}elif(sz>m){
			if(f==0){//第一次
				f=1;
				for(pii x:b[i])c.push_back(x.fi);
				d.resize(c.size()+2);
			}else{
				int cnt=sz;
				for(int j=0;j<b[i].size();j++){
					int id=find(b[i][j].fi);
					if(id!=c.size()&&c[id]==b[i][j].fi)b[i][j].se=1;//出现在c里
					else b[i][j].se=0,cnt--;
				}
				if(cnt==m){//出现了m个
					int ans=-1;
					for(pii x:b[i]){
						if(x.se==1){
							if(ans==-1)ans=x.fi;
							else ans&=x.fi;
						}
					}
					cout<<ans;
					return;
				}else {for(int j=0;j<b[i].size();j++)if(b[i][j].se==1)d[find(b[i][j].fi)]++;}//不够m个往c里计数 nlogn
			}
		}else{
			for(int j=0;j<b[i].size();j++){
				int id=find(b[i][j].fi);
				if(id!=c.size()&&c[id]==b[i][j].fi)b[i][j].se=1;//出现在c里
				else b[i][j].se=0;
			}
			for(int j=0;j<b[i].size();j++)if(b[i][j].se==1)d[find(b[i][j].fi)]++;//不够m个往c里计数 nlogn
		}
	}
	if(c.size()<m)cout<<0;
	else{
		for(int i=0;i<c.size();i++)e[i]={c[i],d[i]};
		sort(e.begin(),e.end(),[&](pii x,pii y){
			return x.se>y.se;
		});
		int ans=-1;
		for(int i=0;i<m;i++){
			if(ans==-1)ans=e[i].fi;
			else ans&=e[i].fi;
		}
		cout<<ans;
	}
}
signed main(){
	string filename="and";
	freopen((filename+".in").c_str(),"r",stdin),freopen((filename+".out").c_str(),"w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int Case=1;
//	cin>>Case;
	while(Case--)solve();
}
