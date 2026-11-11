#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,x,y,ans=2e9;
vector<int> to[1000009];
int rd(){
	int x=0;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
	return x;
}
int dis[1000009];
void solve1(){
	queue<int> q;while(!q.empty()) q.pop();
	for(int i=0;i<(1<<n);i++){
		int ppc=0,cnt=0;
		for(int j=0;j<n;j++)
			if ((i>>j)&1)
				ppc++;
		if (ppc!=k) continue;
		for(int j=1;j<=n;j++)
			dis[j]=2e9;
		for(int j=0;j<n;j++)
			if ((i>>j)&1){
				dis[j+1]=0;
				q.push(j+1);
			}
		while(!q.empty()){
			int u=q.front();q.pop();
			for(int j=0;j<to[u].size();j++){
				int v=to[u][j];
//				cout<<u<<' '<<v<<' ';
				if (dis[u]==0&&dis[v]==0) cnt++;
				if (dis[v]>dis[u]+1){
					dis[v]=dis[u]+1;
					q.push(v); 
				}
			}
		}
//		for(int j=0;j<n;j++) cout<<((i>>j)&1);
//		cout<<endl<<*max_element(dis+1,dis+n+1)<<' '<<cnt<<endl;
		if (cnt==2*(k-2)) ans=min(ans,*max_element(dis+1,dis+n+1));
	}
	return ;
}
void solve2(){
	int m=(n>>1);
	if (k==n) ans=0;
	else if (k>=m) ans=1;
	else ans=ceil((m-k)/4.0)+1;
	return ;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=rd();t=rd();
	while(t--){
		n=rd();k=rd();
		for(int i=1;i<n;i++){
			x=rd();y=rd();
			to[x].push_back(y);
			to[y].push_back(x);
		}
		if (c>=1&&c<=3) solve1();
		else if (c==13||c==14) solve2();
		else solve2();
		printf("%d\n",ans);
		ans=2e9;
		for(int i=1;i<=n;i++) to[i].clear();
	}
	return 0;
}
