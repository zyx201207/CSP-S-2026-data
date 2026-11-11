#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],lst[300005],ans[300005];
struct Point{
	int bace;
	int cl;
	int to;
} d[500005];
vector<int> Son[500005];
void DFS(int x){
	for(int it : Son[x]){
		DFS(it);
		d[x].bace += d[it].bace;
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;i++) scanf("%d",&a[i]);
	for(int i = n;i>=1;i--) if(lst[a[i]] == 0) lst[a[i]] = i;
	for(int i = n;i>=1;i--){
		d[i].bace = 1;
		d[i].cl = a[i];
		d[i].to = lst[a[i]]+1;
		Son[lst[a[i]]+1].push_back(i);
	}
	DFS(n+1);
	for(int i = 1;i<=n;i++){
		ans[a[i]] += d[i].bace;
	}
	for(int i = 1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}/*

Trick||Treat!
*/
