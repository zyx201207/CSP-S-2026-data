#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,b,T;
struct quest{
	ll x,y;
} q[100006];
ll w[25],k[506],t[25][506],ans=0,tmp,D[506][506];
ll path(ll line1,ll line2){
	ll dis[506],q[506],mi;
	memset(dis,0x7fffffff,sizeof(dis));
	bool is[506];
	q[0]=line1;
	dis[line1]=0;
	for(ll i=0;i<n;i++){
		is[q[i]]=true;
		mi=0x7fffffff;
		for(ll j=1;j<=n;j++){
			if(!is[j])dis[j]=min(dis[j],dis[q[i]]+D[q[i]][j]);
			if(dis[j]<mi){
				q[i+1]=j;
				mi=dis[j];
			}
		}
	}

	return dis[line2];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	for(ll i=0;i<501;i++){
		memset(D[i],0x7fffffff,sizeof(D[i]));
		D[i][i]=0;		
	}
	cin>>c>>n>>m>>d>>b;
	ll ai,aj;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>ai>>aj;
			t[ai][i]=aj;
		}
		//if(c>=12&&c<=19)T=aj;
	}
	for(int i=1;i<=b;i++)cin>>q[i].x>>q[i].y;
	for(int ii=1;ii<=m;ii++){
		tmp=0x7fffffff;
		for(int i=1;i<=n;i++){
			if(t[ii][i]>0){
				for(int j=i+1;j<=n;j++){
					if(t[ii][j]>0){
						D[i][j]=min(t[ii][i]+t[ii][j],D[i][j]);
						D[j][i]=D[i][j];
					}
				}
			}		
		}
	}
//	for(int i=1;i<n;i++)cout<<D[1][i];
	for(ll i=1;i<=b;i++){
		for(ll j=1;j<=n;j++){
			if(t[q[i].x][j]>0){
				for(ll jj=1;j<=n;j++){
					if(t[q[i].y][jj]>0)tmp=min(tmp,t[q[i].x][j]+t[q[i].y][jj]+path(j,jj));
				}
			}
		}
		cout<<w[q[i].x]+w[q[i].y]+tmp<<endl;
	}
	
}
