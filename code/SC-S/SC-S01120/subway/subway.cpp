#include<bits/stdc++.h>
using namespace std;
int w[500005];
struct s{
	int id;
	int cnt;
	bool visited[50005];
};
struct station{
	int num;
	int line;
};
vector<station> b[500005];
int times[500005][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int k;
	for(int i=1;i<=n;i++){
		cin>>k;
		int a[500005];
		for(int j=1;j<=k;j++){
			cin>>a[j];
			cin>>times[a[j]][i];
		}
		for(int j=1;j<=k;j++){
			for(int l=1;l<=k;l++){
				if(a[j]!=a[l]){
					station y;
					y.line=i,y.num=a[l];
					b[a[j]].push_back(y);
				}
			}
		}
	}
	for(int u=1;u<=q;u++){
		queue<s> qu;
		int start,end,ans=100000000;
		cin>>start>>end;
		s x;
		x.id=start;
		x.cnt=w[start]+w[end];
		qu.push(x);
		while(!qu.empty()){
			x=qu.front();
			qu.pop();
			if(x.id==end){
				ans=min(ans,x.cnt);
				continue;
			}
			for(int i=0;i<b[x.id].size();i++){
				if(x.visited[b[x.id][i].num]) continue;
				s next;
				next.id=b[x.id][i].num;
				next.visited[x.id]=1;
				next.cnt=x.cnt+times[x.id][b[x.id][i].line]+times[next.id][b[x.id][i].line];
				qu.push(next);
			}
		}
		cout<<ans<<endl; 
	}
	return 0;
}