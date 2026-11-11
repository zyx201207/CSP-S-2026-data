#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5;
const int M=3e3+5;
int c,n,m,d,q;
int w[M],zn[M],f[M][M],va[M][M];
struct node{
	int to,val;
};
vector<node>v[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int k;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			f[i][j]=0x3f;
		}
	}
	memset(va,0x3f,sizeof va);
	for(int i=1;i<=n;i++){
		cin>>k;
		int a1,t1,a2,t2;
		cin>>a1>>t1>>a2>>t2;
		va[a1][a2]=min(va[a1][a2],t1+t2);
		va[a2][a1]=va[a1][a2];
		f[a1][a2]=va[a1][a2];
		f[a2][a1]=va[a2][a1];
	}
	int ans=0;
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	int st,ar;
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>st>>ar;
		ans+=(w[st]+w[ar]);
		ans+=min(f[st][ar],f[ar][st]);
		cout<<f[st][ar]<<" "<<ans<<endl;
	}
	return 0;
}