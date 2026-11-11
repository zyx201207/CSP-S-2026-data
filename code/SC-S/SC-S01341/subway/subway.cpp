#include<bits/stdc++.h>
using namespace std;
long long mi,x,y,k,c,n,m,d,q,w[100000],a,t,l[1000][1000],lr[1000][1000],lll=99999,ll;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=d;j++){
			l[i][j]=-1;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		ll=0;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			l[i][a]=t;
			ll+=l[i][a];
		}
		lll=min(ll,lll);
	}
	if(m==2){
		cout<<w[1]+w[m]+lll;
		return 0;
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		int oo=0;
		for(int u=1;u<=m;u++){
			
		}
		for(int r=1;r<=n;r++){
			for(int j=1;j<=d;j++){
				if(l[r][x]!=-1&&l[r][j]!=-1){
					lr[r][j]=l[r][j]+lr[r][x];
				}else{
					lr[r][j]=-1;
				}
			}
		}
		for(int j=1;j<=n;j++){
			mi=0;
			for(int r=1;r<=d;r++){
				if(lr[r][j]<lr[mi][j]&&lr[r][j]!=-1){
					mi=r;
					oo=lr[mi][j];
				}
			}
			for(int r=1;r<=d;r++){
				if(l[r][j]!=-1){
					lr[r][j]=lr[mi][j];
				}
			}
		}	
		cout<<oo<<endl;
	}
	return 0;
} 
