#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
using namespace std;
int c,n,m,d,q,k,w[500005],xx,yy,ans,step[500005],t[25][500005];
vector<int>a[505];
vector<int>dd[500005];
void dfs(int x){
	if(x==yy)return ;
	for(int i:dd[x]){
		for(int j:a[i]){
			if((x==j||dd[j].size()==1||(step[x]+t[i][x]+t[i][j]>=step[j]&&step[j]!=0))&&j!=yy)continue;
			step[j]=step[x]+t[i][x]+t[i][j];
			dfs(j);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>xx>>yy;
			a[i].pb(xx);
			t[i][xx]=yy;
			dd[xx].pb(i);
		}
	}
	while(q--){
		memset(step,0,sizeof(step));
		ans=0;
		cin>>xx>>yy;
		ans+=w[xx]+w[yy];
		dfs(xx);
		dfs(xx);
		cout<<step[yy]+ans<<'\n';
	}
	return 0;
}
/*
17:09.
spent 1 hour.
dfs is done.
What can I say?
What should I say?
It's only a dfs.
haha.
Is it a dream?
How many scores I can get?
I don't want to think it.
Everything has done. 

17:17.
I can only pass the first?
Oh,I find a mistake.
I don't know how to make it...
I'm going to T3. 
*/
