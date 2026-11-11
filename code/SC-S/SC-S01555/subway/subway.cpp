#include<bits/stdc++.h>
using namespace std;
int n,m,d,Q,c,w[500010],a[510][2010],t[510][2010],k[510],p[1010][1010],q[500010],sum[500010],u[1010][1010],T[1010][1010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	if(7<=c&&c<=11){
		for(int i=1;i<=n;i++){
			p[a[i][1]][a[i][2]]=p[a[i][2]][a[i][1]]=min(t[i][1]+t[i][2],p[a[i][2]][a[i][1]]);
			p[a[i][1]][0]++;
			p[a[i][2]][0]++;
		}
		while(Q--){
			int x,y;
			cin>>x>>y;
			if(p[x][y]!=0){
				cout<<w[x]+p[x][y]+w[y];
			}
			else{
				int l=1,r=1;
				for(int i=1;i<=m;i++){
					sum[i]=0x7fffffff;
				}
				q[r]=x;
				for(int i=l;i<=r;i++){
					for(int j=1;j<=p[q[i]][0];j++){
						if(p[q[i]][j]!=0){
							if(sum[j]>sum[q[i]]+p[q[i]][j]){
								sum[j]=sum[q[i]]+p[q[i]][j];
								q[++r]=j;
							}
						}
					}
					l++;
				}
				cout<<sum[y]+w[x]+w[y]<<endl;
			}
		}
	}
	else if(12<=c&&c<=19){
		int T=t[1][1]*2;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=k[i];j++){
				u[a[i][j]][++u[a[i][j]][0]]=i;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=u[i][0];j++){
				for(int k=1;k<=u[i][0];k++){
					p[u[i][j]][u[i][k]]=1;
					p[u[i][j]][0]++;
				}
			}
		}
		while(Q--){
			int x,y,Min=0x7fffffff,flag=0;
			cin>>x>>y;
			for(int i=1;i<=u[x][0];i++){
				for(int j=1;j<=u[y][0];j++){
					if(u[x][i]==u[y][j]){
						Min=min(Min,T+w[x]+w[y]);
						flag=1;
						break;
					}
				}
				if(flag==1){
					break;
				}
			}
			if(flag==0){
				int M=0x7fffffff;
				for(int s=1;s<=u[x][0];s++){
					int q[50010],l=1,r=1,sum[50010];
					for(int i=1;i<=m;i++){
						sum[i]=0x7fffffff;
					}
					for(int i=1;i<=k[s];i++){
						if(a[s][i]==x)
							sum[u[x][s]]=t[s][i];
					}
					q[r]=u[x][s];
					for(int i=l;i<=r;i++){
						for(int j=1;j<=p[q[i]][0];j++){
							if(p[q[i]][j]!=0){
								if(sum[j]>sum[q[i]]+T){
									sum[j]=sum[q[i]]+T;
									q[++r]=j;
								}
							}
						}
						l++;
					}
					for(int i=1;i<=u[y][0];i++){
						int v;
						for(int j=1;j<=k[u[y][i]];j++){
							if(a[u[y][i]][j]==y){
								v=sum[u[y][i]]+w[x]+w[y]+t[u[y][i]][j];
								break;
							}
						}
						M=min(M,v);
					}
				}
				cout<<M<<endl;
				continue;
			}
			cout<<Min<<endl;
		}
	}
	else{
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				for(int s=1;s<=k[i];s++){
					for(int o=1;o<=k[j];o++){
						if(a[i][s]==a[j][o])
							T[i][j]=t[i][s]+t[j][o];
					}
				}
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=k[i];j++){
				u[a[i][j]][++u[a[i][j]][0]]=i;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=u[i][0];j++){
				for(int k=1;k<=u[i][0];k++){
					p[u[i][j]][u[i][k]]=1;
					p[u[i][j]][0]++;
				}
			}
		}
		while(Q--){
			int x,y,Min=0x7fffffff,flag=0;
			cin>>x>>y;
			for(int i=1;i<=u[x][0];i++){
				for(int j=1;j<=u[y][0];j++){
					if(u[x][i]==u[y][j]){
						Min=min(Min,T[x][y]+w[x]+w[y]);
						flag=1;
						break;
					}
				}
				if(flag==1){
					break;
				}
			}
			if(flag==0){
				int M=0x7fffffff;
				for(int s=1;s<=u[x][0];s++){
					int q[50010],l=1,r=1,sum[50010];
					for(int i=1;i<=m;i++){
						sum[i]=0x7fffffff;
					}
					for(int i=1;i<=k[s];i++){
						if(a[s][i]==x)
							sum[u[x][s]]=t[s][i];
					}
					q[r]=u[x][s];
					for(int i=l;i<=r;i++){
						for(int j=1;j<=p[q[i]][0];j++){
							if(p[q[i]][j]!=0){
								if(sum[j]>sum[q[i]]+T[q[i]][j]){
									sum[j]=sum[q[i]]+T[q[i]][j];
									q[++r]=j;
								}
							}
						}
						l++;
					}
					for(int i=1;i<=u[y][0];i++){
						int v;
						for(int j=1;j<=k[u[y][i]];j++){
							if(a[u[y][i]][j]==y){
								v=sum[u[y][i]]+w[x]+w[y]+t[u[y][i]][j];
								break;
							}
						}
						M=min(M,v);
					}
				}
				cout<<M<<endl;
				continue;
			}
			cout<<Min<<endl;
		}
	}
	return 0;
}