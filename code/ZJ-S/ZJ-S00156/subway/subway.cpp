#include <bits/stdc++.h>
using namespace std;
int CT,n,m,d,j,x,t,T,i,w,ft,ff,line,son,a[100001],mm[100001],f[1000001],
vis[1001],tal[1000001],k[10001],cnt[10001],sub[1001][1001],subt[1001][1001],sta[1001][1001],st,ed,mi;
void ds(int stn,int tm){
	int i,j;
	if(stn==ed){
		mi=min(mi,tm+tal[ed]);
		return ;
	}
	for(i=1;i<=cnt[stn];i++)
		for(j=1;j<=k[sta[stn][i]];j++){
			int line=sta[stn][i],sion=sub[line][j];
			if(vis[sion] ==0){
				
				vis[sion]=1;
				ds(sion,subt[line][sion]+tm+subt[line][stn]);
				vis[sion]=0;
			}
		}
			
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>CT>>n>>m>>d>>T;
	for(i=1;i<=m;i++)cin>>tal[i];
	for(i=1;i<=n;i++){
		cin>>k[i];
		for(j=1;j<=k[i];j++)
			cin>>x>>t,sub[i][j]=x,subt[i][x]=t,sta[x][++cnt[x]]=i;
	}
	if(CT>3){
		while(T--){
		cin>>st>>ed;mi=2e9;
		memset(f,0,sizeof(f));
		t=w=1;a[1]=st;mm[1]=tal[st];f[st]=1;
		while(t<=w){
			ft=a[t];ff=mm[t];
			cout<<ft<<"\n";
			if(ft==ed){
				mi=min(mi,ff+tal[ed]);
			}
			for(i=1;i<=cnt[ft];i++)
				for(j=1;j<=k[sta[ft][i]];j++){
					line=sta[ft][i];
					son=sub[line][j];
					if(f[son]==0){
						f[son]=1;
						a[++w]=son;mm[w]=ff+subt[line][ft]+subt[line][son];
					}
				}
			t++;
		}
		cout<<mi<<"\n";
	}	
	return 0;
	}
	for(i=1;i<=T;i++){
		cin>>st>>ed;mi=2e9;
		vis[st]=1;
		ds(st,tal[st]);
		cout<<mi<<"\n";
	}
	
	return 0;
}//£¡£¿67£¡£¿ 
