#include<bits/stdc++.h>
using namespace std;
struct node{
	int id;
	long long time;
};
long long ans,w[500005],d[505][505],f[505][505],y,sum=0;
int c,n,m,di,q,num,x,yy,xx;
vector<node> v[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(d,0x3f,sizeof(d));
	memset(f,0x3f,sizeof(f));
	cin>>c>>n>>m>>di>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>num;
		for(int j=1;j<=num;j++){
			cin>>x>>y;
			v[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<v[i].size();j++){
			for(int k=0;k<v[i].size();k++){
				if(j==k) continue;
				node op1=v[i][j],op2=v[i][k];
				d[op2.id][op1.id]=d[op1.id][op2.id]=min(d[op1.id][op2.id],op2.time+op1.time);
				d[op2.id][op1.id]=min(d[op2.id][op1.id],op1.time+op2.time);
			}
		}
	}
	for(int i=1;i<=n;i++){
		f[i][i]=0;
		for(int j=1;j<=n;j++){
			if(i!=j)
			f[i][j]=d[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			for(int k=1;k<=n;k++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		ans=0x3f3f3f3f;
		cin>>xx>>yy;
		for(int i=0;i<v[xx].size();i++){
			for(int j=0;j<v[yy].size();j++){
				node op1=v[xx][i],op2=v[yy][j];
				if(op1.id==op2.id) ans=op1.time+op2.time;
				else ans=min(ans,f[op1.id][op2.id]+op1.time+op2.time);
			}
		}
		cout<<ans+w[xx]+w[yy]<<endl;
		//sum+=ans+w[xx]+w[yy];
	}
	//cout<<sum;
	return 0;
}
