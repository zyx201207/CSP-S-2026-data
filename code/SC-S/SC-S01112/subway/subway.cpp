#include<bits/stdc++.h>
using namespace std;
struct que{
	int st,ed;
}stor[100050];
int c,n,m,d,q;
int w[100050],t[100050],ser[100050];
vector<int>of[100050];
bool flag[100050];
bool con(int u,int v){
	for(int i:of[u]){
		if(flag[i]) continue;
		flag[i]=1;
		if(i==v){
			return 1;
		}
		flag[u]=1;
		con(i,v);
	}
	return 0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	int tmp=0;
	for(int i=1;i<=n;i++){
		int tot;
		scanf("%d",&tot);
		for(int j=1;j<=tot;j++){
			scanf("%d%d",&ser[j],&t[j]);
			tmp=t[j];
			if(j>1){
				of[ser[j]].push_back(ser[j-1]);
				of[ser[j-1]].push_back(ser[j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&stor[i].st,&stor[i].ed);
		printf("%d\n",2*tmp+w[stor[i].st]+w[stor[i].ed]);
	}
	
}