#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,f,Q,w[500005],k,x11,y,a[500005],t[500005],s[505][505],d[505][505],p[505];
vector<int>e[505];
queue<int>q;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>f>>Q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}memset(s,0x3f,sizeof(s));
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			for(int ji=1;ji<j;ji++){
				s[a[ji]][a[j]]=s[a[j]][a[ji]]=min(t[j]+t[ji],s[a[ji]][a[j]]);
				e[a[ji]].push_back(a[j]);
				e[a[j]].push_back(a[ji]);
			}
		}
	}memset(d,0x3f,sizeof(d));
	while(Q--){
		cin>>x11>>y;
		if(!d[x11][x11]){
			cout<<d[y][x11]+w[x11]+w[y]<<endl;
			continue;
		}d[x11][x11]=0;
		q.push(x11);
		while(q.size()){
			int x=q.front();
			q.pop();
			p[x]=0;
			for(auto l:e[x]){
				if(d[x][x11]+s[x][l]<d[l][x11]){
					d[l][x11]=d[x][x11]+s[x][l];
					if(!p[l]){
						q.push(l);
						p[l]=1;
					}
				}
			}
		}cout<<d[y][x11]+w[x11]+w[y]<<endl;
	}return 0;
}
