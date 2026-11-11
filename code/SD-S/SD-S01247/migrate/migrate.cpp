#include <bits/stdc++.h>
#define F(J) for(int j=1;j<=J;++j)
using namespace std;
/*
我逆码，上一道题min写成max白费了20min
我看看这道题怎么个事
1e6，nlogn
只剩1.5h了瞅一眼D
留半小时优化A题能优化完再做D
好的我现在有一个假设
把n个点改成(n-1)个距离 
从中找到a b c这样的连续三个数
使得 a+b<=d b+c<=d a+b+c>d
易证明如果d>a+b+c那么这里的路径绝对不止2条
任务就是找到这样的三元组
统计，如果有两个三元组重合则都作废
然后统计前后紧挨着的小于等于d的元素数量 l r 
每个加上(l+1)(r+1)
试试 
不对
我应该先找连续路径
看看里面会不会包括
假设路径1 2 1 2 1里面只有一个的话
算了我先去写A
 
*/
int c,t,n,d,lx,x,dis[2020202],rmv[2020202];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int _=0;_<t;++_){
		lx=0,x=0;
		int ans=0;
		cin>>n>>d;
		F(n){
			lx=x;
			cin>>x;
			dis[j-1]=x-lx;//cout<<dis[j-1]<<endl;
		}vector<int>tri;
		--n;
		dis[0]=0;
		for(int i=2;i<n;++i){
			if(dis[i-1]+dis[i]<=d && dis[i]+dis[i+1]<=d && dis[i]+dis[i+1]+dis[i-1]>d){
				tri.push_back(i);
			}
		}for(int i=1;i<tri.size();++i){
			if(tri[i]-tri[i-1]<=2){
				rmv[i]=rmv[i-1]=t;
			}
		}for(auto i:tri){
			if(rmv[i]-t){
				int l=0,r=0;
				for(int j=i-1;j>0;--j){
					if(dis[j]>d){
						break;
					}++l;
				}for(int j=i+1;j<=n;++j){
					if(dis[j]>d){
						break;
					}++r;
				}ans+=(l+1)*(r+1);
			}
		}cout<<ans<<'\n';
	}
	return 0;
}

