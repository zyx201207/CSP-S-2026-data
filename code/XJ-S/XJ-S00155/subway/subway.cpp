#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int k;
int w[1000005];
int a[505][505],t[505][505];
int x[100005],y[100005];
bool vis[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	int zt[d+1][d+1]={0};
	int xb=0;
	for(int i=1;i<=n;i++){
		for(int l=1;l<=k;l++){
			for(int o=1;o<=n;o++){
				for(int j=1;j<=k;j++){
					if(a[i][l]==a[o][j]&&i!=o&&vis[i][o]!=1&&vis[o][j]!=1){
						zt[i][o]=a[i][l];
						zt[o][j]=a[o][j];
						vis[i][o]=1;
						vis[o][j]=1;
					}
				}
			}
		}
	}
	for(int e=1;e<=q;e++){
		cin>>x[e]>>y[e];
		if(x[e]==y[e]){
			cout<<0<<endl;
			continue;
		}
		int time=0; 
		bool f=0,f1=0;
		int minn=INT_MAX; 
		for(int i=1;i<=n;i++){
			f=0;
			for(int j=1;j<=k;j++){
				if(a[i][j]==x[i]){
					for(int r=1;r<=n;r++){
						for(int o=1;o<=k;o++){
							time=w[x[e]]+t[i][j]+t[i][o]+w[y[e]];
							if(a[i][o]==y[e]){
								minn=time;
								f=1;
							}
						}
						if(f!=1){
							for(int g=1;g<=n;g++){
								for(int p=1;p<=k;p++){
									if(zt[i][g]==p){
										minn=min(t[g][p]+time,minn);
										f=1; 
									}else{
										i++;
										time+=t[g][p];
									}	
								} 
							}	
						}
					}
				}
			}
		}
		cout<<minn<<endl;
	}
	return 0;
}
