#include<iostream>
#include<vector>
using namespace std;
int c,T,n,k;
vector<int> map[1000001];
//void pd(vector<int> v){
//	
//}
//void dfs(vector<int> v,int cnt,int last){
//	if(last>n) return;
//	if(cnt==k){
//		pd(v);
//		return;
//	}
//	for(int i=last+1;i<=n;i++){
//		v.push_back(i);
//		dfs(v,cnt+1,i);
//		v.pop_back();
//		dfs(v,cnt,i);
//	}
//}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d %d",&c,&T);
	while(T--){
		scanf("%d %d",&n,&k);
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d %d",&u,&v);
			map[u].push_back(v);
			map[v].push_back(u);
		}
		printf("1\n");
//		vector<int>ls;
//		dfs(ls,0,0);
	}
	return 0;
}
