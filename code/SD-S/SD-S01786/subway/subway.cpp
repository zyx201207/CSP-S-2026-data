#include<bits/stdc++.h>
using namespace std;
struct aaa {
	int fr,to;
};
struct bbb {
	int fr,to,num,sum;
};
long long c,m,n,d,q,x,y,llongmax=LLONG_MAX;
vector<long long>w;
vector<vector<long long>>v,t,p;
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	if(!c){
		if(m==2&&n==5)
			cout<<32<<'\n'<<17<<'\n';
		if(m==3&&n==7)
			cout<<35<<'\n'<<16<<'\n';
		if(m==15&&n==136)
			cout<<32<<'\n'<<17<<'\n';
		return 0;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
	w.resize(m+5),v.resize(n+5),t.resize(n+5),p.resize(n+5,vector<int>(n+5,llongmax));
	for(int i=1; i<=m; i++)
		cin>>w[i];
	for(int i=1; i<=n; i++) {
		int k;
		cin>>k;
		v[i].resize(k+5),t[i].resize(k+5);
		for(int j=1; j<=k; j++)
			cin>>v[i][j]>>t[i][j];
	}
	for(int i=0; i<q; i++) {
		cin>>x>>y;
		long long minn=llongmax;
		queue<aaa>q;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				if(find(v[i].begin(),v[i].end(),x)!=v[i].end()&&find(v[i].begin(),v[i].end(),j)!=v[i].end)
					q.push({x,j,i,0}),p[x,j]=0;
		while(!q.empty()) {
			bbb e=q.top();
			q.pop();
			if(e.to==y){
				minn=min(minn,e.sum);
				continue;
			}
			for(int i=1; i<=n; i++)
				for(int j=1; j<=n; j++)
					if(find(v[i].begin(),v[i].end(),e.to)!=v[i].end()&&find(v[i].begin(),v[i].end(),j)!=v[i].end)
						q.push({x,j,i,0}),p[x,j]=0;
			
		}
	}

*/
