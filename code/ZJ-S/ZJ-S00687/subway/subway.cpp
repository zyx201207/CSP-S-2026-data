#include<bits/stdc++.h>
#define psbk push_back
using namespace std;
int c,n,m,d,q;
int w[550005];
int k[550005];
long long pmin[500005][5];
struct node{
	vector<int> p,v;
}edge[550005];
int ans[3005][3005];
long long dijkstra(int x,int y){
	queue<int> p,s;
	while(!p.empty()) p.pop();
	while(!s.empty()) s.pop();
	p.push(x);
	s.push(0);
	if(ans[x][y]!=-1) return ans[x][y];
	while(!p.empty()){
		int pp=p.front();
		int step=s.front();
		p.pop(),s.pop();
		for(int i=0;i<edge[pp].p.size();i++){
			int np=edge[pp].p[i];
			int ns=step+edge[pp].v[i];
			
			
			if(ans[x][np]==-1||ans[x][np]>ns){
				p.push(np);
				s.push(ns);
				ans[x][np]=ns;
//				if(np>1005){
//					cout<<'('<<np-1005<<')'<<' '<<ns<<' '<<ans[x][np]<<endl;
//				}
//				else{
//					cout<<np<<' '<<ns<<' '<<ans[x][np]<<endl;
//				}
			}
			
		}
	}
	return ans[x][y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=0;i<2005;i++){
		for(int j=0;j<2005;j++){
			if(i==j){
				ans[i][j]=0;
			}
			else{
				ans[i][j]=-1;
			}
				
		}
	}
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	long long vmin=2147483647;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int p,v;
			cin>>p>>v;
			edge[i+1005].p.psbk(p);
			edge[i+1005].v.psbk(v);
			edge[p].p.psbk(i+1005);
			edge[p].v.psbk(v);
			if(n<=2){
				if(pmin[p][i]==0){
					pmin[p][i]=v;
				}
			}	
			if(pmin[p][1]&&pmin[p][2]){
				vmin=min(vmin,pmin[p][1]+pmin[p][2]);
			}	
		}
	}
	if(n<=2){
//		cout<<"P"<<endl;
		while(q--){
			int x,y;
			cin>>x>>y;
			long long anss=10000000000;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(pmin[x][i]&&pmin[y][j]){
						if(i!=j){
							anss=min(anss,pmin[x][i]+pmin[y][j]+vmin);
						}
						else{
							anss=min(anss,pmin[x][i]+pmin[y][j]);
						}
					}
					
				}
			}
			anss+=w[x]+w[y];
			cout<<anss<<endl;
		}
		return 0;
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		long long anss=0;
		anss=dijkstra(x,y)+w[x]+w[y];
		cout<<anss<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/