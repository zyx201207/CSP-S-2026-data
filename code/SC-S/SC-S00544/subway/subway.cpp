#include<bits/stdc++.h>
using namespace std;
const int N=500010,M=800010;
map<long long,int>fi;
int c,n,m,d,p,l,r;
int st[N],a[N],dist[N];
int idx,e[M],ne[M],h[M],w[M];
bool b[N];
void add(int x,int y,int z){
	idx++;
	e[idx]=y;
	w[idx]=z;
	ne[idx]=h[x];
	h[x]=idx;
}
int idx1,e1[N],ne1[N],h1[N],w1[N];
void add1(int x,int y,int z){
	idx1++;
	e1[idx1]=y;
	w1[idx1]=z;
	ne1[idx1]=h1[x];
	h1[x]=idx1;
}
queue<int>q;
void bfs(){
	memset(dist,0x3f,sizeof(dist));
	q.push(l);
	dist[l]=0;
	while(q.size()!=0){
		int t=q.front();
		b[t]=false;
		q.pop();
		for(int i=h[t];i!=0;i=ne[i]){
			int j=e[i];
			if(w[i]+dist[t]<dist[j]){
				dist[j]=w[i]+dist[t];
				if(b[j]==false){
					q.push(j);
					b[j]=true;
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>p;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++){
		int t;
		cin>>t;
		for(int j=1;j<=t;j++){
			int x,y;
			cin>>x>>y;
			add1(i,x,y);
			st[x]++;
		}
	}
	for(int t=1;t<=m;t++){
		for(int i=h1[t];i!=0;i=ne1[i]){
			int j=e1[i];
			if(st[j]>=2){
				for(int ii=h1[t];ii!=0;ii=ne1[ii]){
					int jj=e1[ii];
					//cout<<t<<" "<<j<<jj<<endl;
					if(j==jj)continue;
					if(st[jj]>=2)add(j,jj,w1[i]+w1[ii]);
					else{
						add(j,jj,w1[i]+w1[ii]);
						add(jj,j,w1[i]+w1[ii]);
					}
				}
			}
			for(int ii=h1[t];ii!=0;ii=ne1[ii]){
				int jj=e1[ii];
				fi[jj*N+j]=fi[j*N+jj]=w1[i]+w1[ii];
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<i<<"："; 
//		for(int j=h[i];j!=0;j=ne[j])cout<<e[j]<<"-"<<w[j]<<"    ";
//		cout<<endl;
//	}
	for(int i=1;i<=p;i++){
		cin>>l>>r;
		if(fi[l*N+r]==0){
			bfs();
			cout<<dist[r]+a[l]+a[r]<<endl;
		}else{
			cout<<fi[l*N+r]+a[l]+a[r]<<endl;
		}
	}
	return 0;
}