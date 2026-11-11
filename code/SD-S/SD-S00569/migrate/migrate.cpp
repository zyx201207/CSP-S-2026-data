#include<bits/stdc++.h>

using namespace std;
int n,t,sss,d,m[200000000],mi[100000000][2];
void dfs(int x,int val) {
	if(x>=n) return ;
	if(mi[x][0]!=0) {
		if(mi[x][1]<val) {
			mi[x][0]=1;
			mi[x][1]=val;
		} else if(mi[x][1]==val);
		{
			mi[x][0]++;
		}
	}
	mi[x][0]=1;
	mi[x][1]=val;
	for(int i=x+1; i<x+d; i++) {
		if(m[i]-m[x]<=d);
		{
			dfs(m[i],val+1);
		}
	}
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>sss>>t;
	for(int k=0; k<t; k++) {
		int ans=0;
		cin>>n>>d;
		for(int i=0; i<n; i++) {
			cin>>m[i];

		}
		dfs(m[0],0);
		for(int i=0; i<=m[n]+1; i++) {
			if(mi[i][0]>1) {
				ans++;
			}
		}
		cout<<ans<<"\n";
		memset(mi,0,sizeof(mi));


	}
	return 0;
}
