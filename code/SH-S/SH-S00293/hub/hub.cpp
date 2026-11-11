#include<bits/stdc++.h>
using namespace std;
namespace solve1{
	int t,n,k,ml[5010],bp,f[5010],bl[5010],ans[3][5010];
	vector<int> e[5010];
	void dfs_l(int u,int fa,int bad){
		ml[u]=ml[fa]+1;
		f[u]=fa;
		if(ml[u]>ml[bp])
			bp=u;
		for(auto g:e[u])
			if(g!=fa&&g!=bad){
				dfs_l(g,u,bad);
			}
	}
	void dfs_b(int u,int fa,int bad){
		bl[u]=1;
		f[u]=fa;
		for(auto g:e[u])
			if(g!=fa&&g!=bad){
				dfs_b(g,u,bad);
				bl[u]=max(bl[u],bl[g]+1);
			}
//		cout<<u<<","<<bl[u]<<" "<<f[u]<<endl;
	}
	void solpart(int u,int fa,int si){
		ml[u]=0;
		dfs_l(u,fa,fa);
		int lf=bp;
		ml[lf]=0;
		dfs_l(lf,0,fa);
		int pos=bp;
		for(int i=0;i<ml[bp]/2;i++)
			pos=f[pos];
		dfs_b(pos,0,fa);
		priority_queue<pair<int,int> > pq;
		int i=1;
		pq.push(make_pair(bl[pos],pos));
		for(i=1;pq.size();i++){
//			cout<<i<<":"<<pq.top().first<<"!!\n";
			ans[si][i-1]=pq.top().first;
			int u=pq.top().second;
			pq.pop();
			for(auto g:e[u])
				if(g!=f[u]&&g!=fa)
					pq.push(make_pair(bl[g],g));
		}
		for(int j=i-1;j<=k;j++)
			ans[si][j]=0;
//		cout<<pos;
		ans[si][0]=0x3f3f3f3f;
//		cout<<u<<",main,"<<fa<<":\n";
////		cout<<lf<<","<<pos<<","<<i<<":\n";
//		for(int i=0;i<=k;i++)
//			cout<<ans[si][i]<<" ";
// 		cout<<endl;
//		cout<<endl;
//		cout<<endl;
	}
	int gans=0x3f3f3f3f;
	void sol(int u,int fa){
		if(fa){
			solpart(u,fa,0);
			solpart(fa,u,1);
			for(int i=0;i<=k;i++)
				gans=min(gans,max(ans[0][i],ans[1][k-i]));
		}
		for(auto g:e[u])
			if(g!=fa)
				sol(g,u);
	}
	void s1(){
		scanf("%d",&t);
		while(t--){
			scanf("%d%d",&n,&k);
			for(int i=1,u,v;i<n;i++){
				scanf("%d%d",&u,&v);
				e[u].emplace_back(v);
				e[v].emplace_back(u);
			}
			if(k==1){
				solpart(1,0,0);
				gans=ans[0][1];
			}
			else{
				sol(1,0);
				solpart(3,2,0);
				solpart(2,3,0);
			}
			printf("%d\n",gans);
			gans=0x3f3f3f3f;
//			sol(1,0);
			for(int i=1;i<=n;i++)
				e[i].clear();
		}
	}
}
namespace solve2{
	int t,n,k;
	void s2(){
		scanf("%d",&t);
		while(t--){
			scanf("%d%d",&n,&k);
			for(int i=1,u,v;i<n;i++){
				scanf("%d%d",&u,&v);
			}
			if(k==n)
				printf("0\n");
			else if(k==1){
				printf("%d\n",n/4+1);
			}
			else{
				int m=n/2;
				if(k>=m){
					printf("1\n");
				}
				else{
					if(m%2==0||k%2==1){
						printf("%d\n",(m/2-k/2+1)/2+1);
					}
					else{
						printf("%d\n",(m/2-k/2+2)/2+1);
					}
				}
			}
		}
	}
}
int c;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d",&c);
	if(c<=10){
		solve1::s1();
	}
	else if(c==13||c==14){
		solve2::s2();
	}
	return 0;
} 
