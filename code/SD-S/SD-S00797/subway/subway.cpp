#include<bits/stdc++.h>
using namespace std;
void dfs(int x){
	if{x==0}
	{
		
	}
	ans+=dfs()
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,zhan[1005]={},xianlu[1005][4],p[10005][2],ans=0,lianjie[1005]={};
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)	cin>>zhan[i];
	for(int i=0;i<n;i++){
		int j;
		cin>>j;
		for(int t=0;t<j;t++){	
			cin>>xianlu[t][0]>>xianlu[t][1]>>xianlu[t][2]>>xianlu[t][3];
			lianjie[xianlu[t][1]]++;
			lianjie[xianlu[t][3]]++;
		}
	}
	for(int i=0;i<q;i++)	cin>>p[i][0]>>p[i][1];
	for(int i=0;i<q;i++)
	{
		ans=0;
		dfs()
		
		ans+=zhan[p[i][0]];
		ans+=zhan[p[i][1]];
		cout<<ans;
	}
	
	
	
	return 0;
}
