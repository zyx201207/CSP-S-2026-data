#include<bits/stdc++.h> 
using namespace std;
long long c,n,m,d,q,w[500005],a[500005],t[500005],p[1005][1005],x,y,v,z[1005],kk=0;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++) p[i][j]=2*1e9+5;
	}
	for(int j=1;j<=n;j++){
		long long k;
		cin>>k;
		for(int i=1;i<=k;i++) cin>>a[i]>>t[i];
		for(int i=1;i<=k-1;i++){
			for(int h=i+1;h<=k;h++){
				if(t[i]+t[h]<p[a[i]][a[h]]||t[i]+t[h]<p[a[h]][a[i]]){
					p[a[i]][a[h]]=t[i]+t[h];
					p[a[h]][a[i]]=t[i]+t[h];
				}
			}
		}
	}
	for(int i=1;i<m;i++){
		for(int j=i+1;j<=m;j++){
			if(p[i][j]==2*1e9+5){
				v=0;
				while(v<=m){
					v++;
					if(v==i||v==j) kk=1;
					else if(p[v][i]==2*1e9+5||p[v][j]==2*1e9+5||p[v][i]==0||p[v][j]==0) kk=1;
					else{
						p[i][j]=min(p[i][j],p[v][i]+p[v][j]);
						p[j][i]=p[i][j];
					}
				}
			}
		}
	}
	for(int g=1;g<=q;g++){
		cin>>x>>y;
		cout<<p[x][y]+w[x]+w[y]<<'\n';
	}
	return 0;
}
