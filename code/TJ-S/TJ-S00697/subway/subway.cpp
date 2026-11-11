#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
vector<int> st[500005];
vector<int> cost[500005];
vector<int> rd[1000];
vector<int> costrd[1000];
long long rdrd[600][600];
long long mn[600][600];
int tiiim[500005];
int que[400000],hq=1,qt=0;
int spfa(){
	for(int i=1;i<=n;i++){
		memset(que,0,sizeof(que));
		hq=1,qt=0;
		que[1]=i;
		qt=1;
		while(qt>=hq){ //que[hq]
			for(int j=1;j<=n;j++){
				if(mn[i][j]>mn[i][que[hq]]+rdrd[que[hq]][j]){
					qt++;
					que[qt]=j;
					mn[i][j]=min(mn[i][j],mn[i][que[hq]]+rdrd[que[hq]][j]);
					mn[j][i]=mn[i][j];
				}
			}
			hq++;
		}
	}
	return 0;
}

int main()
{
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=1;i<=505;i++){
		for(int j=1;j<=505;j++)if(i!=j)rdrd[i][j]=mn[i][j]=11451419198101145;
	}
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>tiiim[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,b;
			cin>>a>>b;
			st[a].push_back(i);
			cost[a].push_back(b);
			rd[i].push_back(a);
			costrd[i].push_back(b);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<st[i].size()-1;j++){
			for(int k=j+1;k<st[i].size();k++){
				int tim=cost[i][j]+cost[i][k];
				rdrd[st[i][j]][st[i][k]]=tim;
				rdrd[st[i][k]][st[i][j]]=tim;
			}
		}
	}
	spfa();
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		long long ans=11451419198101145;
		for(int j=0;j<st[x].size();j++){
			for(int k=0;k<st[y].size();k++){
				ans=min(ans,cost[x][j]+cost[y][k]+mn[st[x][j]][st[y][k]]);
			}
		}
		cout<<ans+tiiim[x]+tiiim[y]<<"\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
*/
