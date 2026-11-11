#include<bits/stdc++.h>
using namespace std;

const long long maxn=2005;
long long c,n,m,d,q,x,y,ans,k[505];
long long w[maxn],a[505][maxn],t[505][maxn];
long long dq[maxn];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int r=1;r<=q;r++){
		cin>>x>>y;
		int h=0,tt=0,s=0,ti=0;
		ans=1e9;
		while(h<=tt){	
			for(int i=1;i<=n;i++){
				ti+=t[i][dq[h]];
				for(int j=1;j<=k[i];j++){
					if(a[i][j]==dq[h]){
						for(int kk=1;kk<=k[i];kk++){
							if(a[i][kk]!=a[i][j])dq[++tt]=a[i][kk];
							if(a[i][kk]==y){
								ans=min(ti+t[i][kk],ans);
							}
						}
					}
					else ti-=t[i][dq[h]];
				}	
			}	
			h++;
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}