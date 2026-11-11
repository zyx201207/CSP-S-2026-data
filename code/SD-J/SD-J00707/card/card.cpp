#include <iostream>
#include <queue>
using namespace std;
const int N=5e5+5,M=3e5+5;
int a[N];
int cnt[M];
bool vis[M];
int n,m;
deque<int>q;
void solve(int x){
	fill(vis+1,vis+1+m,0);
	q.clear();
	for(int i=x;i<=n;i++){
		if(!vis[a[i]]){
			q.push_back(a[i]);
			vis[a[i]]=1;
		} 
		else{
			while(q.back()!=a[i]){
				vis[q.back()]=0;
				q.pop_back();
			} 
		}
	}
	while(!q.empty()){
		cnt[q.back()]++;
		q.pop_back();
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		solve(i);
	}
	for(int i=1;i<=m;i++){
		printf("%d ",cnt[i]);
	}
	return 0;
}
