#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,head[500505],lcnt=0,w[550005],k,a,t,X,Y,f[505][550005],vis[550005];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >Q;
struct node{
	int nxt,to,ct;
}lin[2000005];
void addline(int fm,int To,int cst){
	lin[++lcnt].ct=cst,lin[lcnt].nxt=head[fm],lin[lcnt].to=To;
	head[fm]=lcnt;
}void dj(int t){
	Q.push(make_pair(0,t));
	while(Q.size()){
		int g=Q.top().first,s=Q.top().second;
		Q.pop();
		if(!vis[s]){
			vis[s]=1;
			f[t][s]=g;
			for(int i=head[s];i;i=lin[i].nxt){
				if(!vis[lin[i].to]){
					Q.push(make_pair(g+lin[i].ct,lin[i].to));
				}
			}
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=n;i++){
		cin>>k;
		for(int l=1;l<=k;l++){
			cin>>a>>t;
			addline(i,a+500,t);
			addline(a+500,i,t);
		}
	}for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		dj(i);
	}
	for(int i=1;i<=q;i++){
		cin>>X>>Y;
		int Ans=1e9+5;
		for(int i=1;i<=n;i++){
			Ans=min(Ans,f[i][X+500]+f[i][Y+500]);
		}cout<<Ans+w[X]+w[Y]<<endl;
	}
	return 0;
}
