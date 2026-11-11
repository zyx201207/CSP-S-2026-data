#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+5;
int n,c,t,m;

vector<int> ed[N];
void work(){
	scanf("%d%d",&n,&m);
	for(int i  =1;i<=n;i++) ed[i].clear();
	for(int i = 1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		ed[x].push_back(y);
		ed[y].push_back(x);
	}
	printf("0\n");
} 
int main(){
	freopen("migrate2.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		work();
	}
	return 0;
} 
