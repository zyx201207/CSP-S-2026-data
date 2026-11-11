#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d1,q;
int w[510],a[500010][3],t[500010][3],d[500010],sa[500010],rd[510][510];
void road1(){
	for(int p=1;p<=n;p++)
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				for(int k=j+1;k<=m;k++){
					if(rd[j][i]!=0&&rd[i][k]!=0)
						rd[j][k]=rd[k][j]=min(rd[j][i]+rd[i][k],rd[j][k]);
				}
			}
		}
}
void solve(){
	int p=0;
	for(int i=1;i<=m;i++){
		if(d[i]==2){
			p++;
			sa[p]=d[i];
		}
	}
	while(q--){
		int s,t;
		cin>>s>>t;
		for(int i=1;i<=p;i++)
			rd[s][t]=rd[t][s]=min(rd[s][t],rd[s][sa[i]]+rd[sa[i]][t]);
		cout<<w[s]+w[t]+rd[s][t]<<endl;
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d1>>q;
	memset(rd,0x3f,sizeof(rd));
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int p;
		cin>>p;
		for(int j=1;j<=p;j++){
			cin>>a[i][j]>>t[i][j];
			d[a[i][j]]++;
		} 
		for(int j=1;j<=p;j++){
			for(int k=j;k<=p;k++){
				if(j==k) continue;
				rd[a[i][j]][a[i][k]]=rd[a[i][k]][a[i][j]]
				=min(rd[a[i][k]][a[i][j]],t[i][j]+t[i][k]);
			}
		}
	}
	if(c==20||c==21) solve();
	else road1();
	while(q--){
		int s,t;
		cin>>s>>t;
		cout<<w[s]+w[t]+rd[s][t]<<endl;
	}
	return 0;
}
