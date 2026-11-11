#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[500005],k[500005],a[10005][10005],t[10005][10005],x,y;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
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
	int time=4;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		for(int j=1;j<=n;j++){
			for(int s=1;s<=k[j];s++){
				for(int su=1;su<=n;su++){
					if(a[x][s]==x&&a[su][y]==y){
						time+=t[x][y];
					}
					else{
						if(a[x][s]==a[su][y]){
							time+=time+t[x][s]+t[su][y];
						}
					}
				}
			}
		}
		cout<<time%35<<endl;
		memset(a,0,sizeof(a));
		memset(t,0,sizeof(t));
		time=4;
	}
		return 0;
}
