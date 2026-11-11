#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,W[1010],i,j,er[10],x,y,A[10010],T[1010],book[1010][1010],F[1010][1010];
vector<int> V[1010];
queue<int> Q;
void dfs(int x){
	int i,j,t;
	for(i=0;i<V[x].size();i++){
		Q.push(V[x][i]);
	}
	while(!Q.empty()){
		t=Q.front();Q.pop();
		for(i=0;i<V[t].size();i++){
			if(x==V[t][i]) continue;
			if(F[x][V[t][i]]==0||F[x][V[t][i]]>F[x][t]+F[t][V[t][i]]){
				Q.push(V[t][i]);
				F[x][V[t][i]]=F[x][t]+F[t][V[t][i]];
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(i=1;i<=m;i++){
		scanf("%d",&W[i]);
	}
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		for(j=1;j<=k;j++){
			scanf("%d%d",&A[j],&T[j]);
		}
		for(j=1;j<=k;j++){
			for(int u=1;u<j;u++){
				if(F[A[j]][A[u]]>T[j]+T[u]||F[A[j]][A[u]]==0){
					F[A[u]][A[j]]=T[u]+T[j];
					F[A[j]][A[u]]=T[j]+T[u];
				}
				if(book[A[j]][A[u]]==0){
					book[A[j]][A[u]]=1;
					book[A[u]][A[j]]=1;
					V[A[j]].push_back(A[u]);
					V[A[u]].push_back(A[j]);
				}
			}
		}
	}
	for(i=1;i<=m;i++){
		dfs(i);
	}
	for(i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		printf("%d\n",F[x][y]+W[x]+W[y]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
