#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long w[N],a[N][N],t[N][N],x[N],y[N],ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q,k;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=0;i<q;i++){
		cin>>x[i]>>y[i];
	}
	for(int r=0;r<q;r++){
		for(int i=0;i<n;i++){
			if(a[i][0]==x[r]){
				for(int j=0;j<k;j++){
					if(a[i][j]==y[r]){
						ans=w[i]+t[i][0]+t[i][j]+w[j];
						break;
					}else{
						for(int b=0;b<n;b++){
							for(int d=0;d<k;d++){
								if(a[b][d]==a[i][j]&&a[b][k-1]==y[r]){
									ans=w[i]+t[i][0]+t[i][j]+t[b][d]+t[b][k-1]+w[b];
								}
							}
						}
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
