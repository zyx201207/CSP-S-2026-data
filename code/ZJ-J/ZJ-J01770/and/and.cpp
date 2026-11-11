#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
int n,m,ans;
vector <int> e[40];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		e[31].push_back(x);
	}
	for(int i=30,now;i>-1;i--){
		now=(1<<i);
		for(int j=0;j<e[i+1].size();j++)if(e[i+1][j]&now)e[i].push_back(e[i+1][j]);
		if(e[i].size()>=m)ans+=now;
		else{
			for(int j=0;j<e[i].size();j++)e[i][j]=e[i+1][j];
			for(int j=e[i].size();j<e[i+1].size();j++)e[i].push_back(e[i+1][j]);
		}
	}
	printf("%d\n",ans);
	return 0;
}