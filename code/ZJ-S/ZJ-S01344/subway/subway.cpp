#include<bits/stdc++.h>
using namespace std;
struct p{
	int T,place,num;
};
int n,w[500010],k[500010],a[510][50010],g[50010][40],cnt1[40],cnt[510],t[510][50010],c,f=1,e=1,m,d,q1,used[510][50010];
p q[500010],s[500010],t1[500010];
void bfs(){
	while(e<=f){
		int x;
		p u=q[f++],v;
		if(u.num==-1)	x=0;
		else x=cnt[u.num];
		for(int i=1;i<=x+cnt1[u.place];i++){
			if(i<=x){
				if(u.num==-1)	continue;
				v.place=a[u.num][i],v.T=u.T,v.num=u.num;
				if(used[v.num][v.place]!=-1){
					if(used[v.num][v.place]<v.T)	continue;
					else	used[v.num][v.place]=v.T;
				}
				used[v.num][v.place]=v.T;
				q[++e]=v;
			}
			else{
				if(u.num==-1){
					v.place=u.place,v.T=u.T+t[g[u.place][i-x]][u.place],v.num=g[u.place][i-x];
					if(used[v.num][v.place]!=-1){
						if(used[v.num][v.place]<v.T)	continue;
						else	used[v.num][v.place]=v.T;
					}
				}
				else{
					v.place=u.place,v.T=u.T+t[u.num][u.place],v.num=-1;
					if(used[v.num][v.place]!=-1){
						if(used[v.num][v.place]<v.T)	continue;
						else	used[v.num][v.place]=v.T;
					}
				}
				used[v.num][v.place]=v.T;
				q[++e]=v;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	cin>>c>>n>>m>>d>>q1;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][a[i][j]];
			cnt[i]=k[i];
			cnt1[a[i][j]]++;
			g[a[i][j]][j]=i;
		}
	}
	for(int i=1;i<=q1;i++){
		cin>>s[i].place>>t1[i].place;
		memset(used,-1,sizeof(used));
		used[-1][s[i].place]=0;
		f=e=1;
		s[i].T=0;
		s[i].num=-1;
		q[1]=s[i];
		bfs();
		cout<<used[-1][t1[i].place]<<endl;
	}
	return 0;
}
