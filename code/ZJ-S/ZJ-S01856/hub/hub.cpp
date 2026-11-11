#include<bits/stdc++.h>
using namespace std;
int C,T,n,k,v[15],vi[15],ans,d[15],an;
vector<int> tu[15];
void dfs(int now){
	vi[now]=1;
	for(int to:tu[now]){
		if(vi[to]==0&&v[to]==1){
			dfs(to);
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&C,&T);
	while(T--){
		ans=0x3f3f3f3f;
		scanf("%d%d",&n,&k);
		if(C<=3){
			for(int i=1;i<=n;i++){
				tu[i].clear();
			}
			for(int i=1,x,y;i<n;i++){
				scanf("%d%d",&x,&y);
				tu[x].push_back(y);
				tu[y].push_back(x);
			}
			int sl=(1<<n);
			for(int i=0;i<sl;i++){
				int cnt=0;
				for(int j=0;j<n;j++){
					if((i>>j)&1){
						cnt++;
						v[j+1]=1;
					}else{
						v[j+1]=0;
					}
				}
				if(cnt!=k){
					continue;
				}
				for(int j=1;j<=n;j++){
					vi[j]=0;
				}
				cnt=0;
				for(int j=1;j<=n;j++){
					if(vi[j]==0&&v[j]==1){
						dfs(j);
						cnt++;
					}
				}
				if(cnt>2){
					continue;
				}
				queue<int> q;
				for(int j=1;j<=n;j++){
					vi[j]=0;
					if(v[j]){
						vi[j]=1;
						q.push(j);
						d[j]=0;
					}
				}
				an=0;
				while(!q.empty()){
					int now=q.front();
					q.pop();
					for(int to:tu[now]){
						if(vi[to]==0){
							vi[to]=1;
							q.push(to);
							d[to]=d[now]+1;
							an=max(an,d[to]);
						}
					}
				}
				ans=min(ans,an);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
