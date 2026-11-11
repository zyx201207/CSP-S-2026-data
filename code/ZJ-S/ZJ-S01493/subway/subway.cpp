#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=505,NODE=6e5+5;
const LL inf=1e17;
LL in(){
	LL aa=0,bb=1;
	char cc=getchar();
	while(cc<'0'||cc>'9'){
		if(cc=='-')	bb=-1;
		cc=getchar();
	}
	while(cc>='0'&&cc<='9'){
		aa=(aa<<3)+(aa<<1)+(cc^48);
		cc=getchar();
	}
	return aa*bb;
}
void out(LL aa){
	if(aa<0){
		aa=-aa;
		putchar('-');
	}
	if(aa<=9)	putchar(aa+'0');
	else{
		out(aa/10);
		putchar(aa%10+'0');
	}
	return ;
}

LL dp[N][N],cst[NODE];
vector<LL> bel[NODE];
map<int , LL> road[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//out(5*(1e5)*20*20);
	LL c=in(),n=in(),m=in(),d=in(),q=in();
	for(int i=1;i<=N-2;i++){
		for(int j=1;j<=N-2;j++)	dp[i][j]=inf;	
	}
	for(int i=1;i<=N-2;i++)	dp[i][i]=0;
	
	for(int i=1;i<=m;i++)	cst[i]=in();
	for(int i=1;i<=n;i++){
		LL len=in();
		for(int j=1;j<=len;j++){
			LL pos=in(),tim=in();
			bel[pos].push_back(i);
			road[i][pos]=tim;
		}
	}
	for(int i=1;i<=m;i++){
		for(int x=0;x<bel[i].size()-1;x++){
			for(int y=x+1;y<bel[i].size();y++){
				LL u=bel[i][x],v=bel[i][y];
				dp[u][v]=dp[v][u]=min(dp[u][v],road[u][i]+road[v][i]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	while(q--){
		LL l=in(),r=in(),ans=inf;
		for(int i=0 ; i<bel[l].size();i++){
			for(int j=0 ; j<bel[r].size();j++){
				LL u=bel[l][i],v=bel[r][j];
				ans=min(ans,dp[u][v]+road[u][l]+road[v][r]);
			}
		}
		ans+=cst[l]+cst[r];
		out(ans);
		putchar('\n');
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
