#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000010],dis[2000010],ways[2000010];
vector<long long>g[2000010];

long long sv1_10(){
	for(long long i=1;i<=n;i++){
		g[i].clear();
	}
	for(long long u=1;u<=n;u++){
		for(long long v=u+1;v<=n;v++){
			if(x[v]-x[u]>d) continue;
			g[u].push_back(v);
		}
	}
	long long ans=0;
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			dis[j]=1e9;
			ways[j]=0;
		}
		//cout<<i<<endl;
		queue<long long>q;
		q.push(i);
		dis[i]=0;
		ways[i]=1;
		while(q.size()){
			long long p=q.front();
			q.pop();
			//cout<<endl<<p<<' ';
			for(long long j=0;j<g[p].size();j++){
				if(dis[g[p][j]]>dis[p]+1){
					//cout<<p<<"->"<<g[p][j]<<' ';
					dis[g[p][j]]=dis[p]+1;
					ways[g[p][j]]=1;
					q.push(g[p][j]);
				}
				else if(dis[g[p][j]]==dis[p]+1){
					//cout<<p<<"->>"<<g[p][j]<<' ';
					ways[g[p][j]]++;
				}
			}
		}
		//cout<<endl;
		for(long long j=1;j<=n;j++){
			if(ways[j]==2) ans++;
			//if(dis[j]==1e9) cout<<"(X)|";
			//else cout<<'('<<dis[j]<<')'<<"|";
		}
		//cout<<endl<<' ';
		//for(long long j=1;j<=n;j++){
			//cout<<ways[j]<<" | ";
		//}
		//cout<<endl<<endl;
	}
	return ans;
}


int main(){
	//freopen()
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>x[i];
		}
		cout<<sv1_10()<<endl;
		//else if(c==11||c==12) cout<<svA()<<endl;
	}
	//fclose()
	fclose(stdin);
	fclose(stdout);
	return 0;
	//Exoplanetary Mirage
}






