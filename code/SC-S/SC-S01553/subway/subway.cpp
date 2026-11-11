#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,r,e[505],ma[505][505],inq[505],dis[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>r;
	for(int i=1;i<=m;i++){
		cin>>e[i];
	}
	for(int i=1;i<=500;i++){
		for(int j=1;j<=500;j++){
			ma[i][j]=1e18;
			dis[i][j]=1e18;
		}
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int la=0,lt=0,a[100005],t[100005];
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<=k;j++){
			for(int g=j+1;g<=k;g++){
				ma[a[j]][a[g]]=min(ma[a[j]][a[g]],t[j]+t[g]);
				ma[a[g]][a[j]]=min(ma[a[g]][a[j]],t[j]+t[g]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		memset(inq,0,sizeof(inq));
		queue<int> q;
		q.push(i);
		inq[i]=1;
		dis[i][i]=0;
		while(!q.empty()){
			int f=q.front();
			for(int j=1;j<=m;j++){
				if(ma[f][j]!=1e18){
					if(dis[i][f]+ma[f][j]<dis[i][j]){
						if(!inq[j]){
							q.push(j);
						}
						dis[i][j]=dis[i][f]+ma[f][j];
						inq[j]=1;
					}
				}
			}
			inq[f]=0;
			q.pop();
		}
	}
	for(int i=1;i<=r;i++){
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]+e[x]+e[y]<<endl;
	}
	return 0;
}