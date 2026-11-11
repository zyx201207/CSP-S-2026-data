#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N][N],t[N][N];
struct hc{
	long long h1,h2,lh1,lh2;
}h[N];
long long c,n,m,d,q,k,w[N],x,y,sum,ans=N;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>d>>q>>k;
	for(int i=1;i<=m;i++)cout<<w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		cin>>x>>y;
		sum+=w[x]+w[y];
		int f=2;
		for(int o=1;o<=n;o++){
			long long tx=0,ty=0;
			for(int i=1;i<=n;i++){
				if(a[o][i]==x){
					tx=i;
					f--;
				}if(a[o][i]==y){
					ty=i;
					f--;
				}
			}
			if(f==0){
				sum+=t[o][tx]+t[o][ty];
				ans=min(ans,sum);
				f=2;
				continue;
			}
			else if(f==1){
				if(tx!=0){
					for(int i=1;i<=m;i++){
						for(int j=1;j<=n;j++){
							if(i==o)continue;
							if(a[i][j]=y){
								for(int g=1;g<=n;g++){
									for(int h=1;h<=n;h++){
										if(a[i][j]=a[g][h]){
											sum+=t[i][j]+t[g][h];
										}
									}
								}
							}
						}
					}
				}
			}else continue;
		}
	}
	return 0;
}
