#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int a[500005][25],w[500005],t[500005][25];
bool vis[500005][25];
struct z{
	int x;
	int y;
};

int main(){
	queue <z> s;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k,t1,t2,t3,t4;
		cin>>k;
		cin>>t1>>t2;
		for(int j=2;j<=k;j++){
			cin>>t3>>t4;
			a[t1][i]=t3;
			t[t1][i]=t2;
			a[t3][i]=t1;
			t[t3][i]=t2;
			t1=t3;
			t2=t4;
		}
	}
	int xr,yr;
	for(int l=1;l<=q;l++)
	z h;

	cin>>xr>>yr;
	s.pushback();
	int ans=w[xr]+w[yr];
	int nx=xr;
	while(!s.empty()){

		s.pop();
		
		for(int i=1;i<=d;i++){
			if(a[nx][i]==0) continue;
			ans+=t[nx][i];
			
		}
	}
	return 0;
}
