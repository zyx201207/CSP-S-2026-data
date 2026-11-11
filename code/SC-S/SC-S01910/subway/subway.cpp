#include<bits/stdc++.h>
using namespace std;
long long int w[1001],a[501][1001][3],h[501];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(false),cout.tie(false);
	srand(time(0));
	long long int c,n,m,d,p;cin>>c>>n>>m>>d>>p;
	for(long long int i=1;i<=m;i++) cin>>w[i];
	for(long long int i=1;i<=n;i++){
		cin>>h[i];
		for(long long int j=1;j<=h[i];j++){
			cin>>a[i][j][1]>>a[i][j][2];
		}
	}
	for(long long int i=1;i<=p;i++){
		long long int x,y;cin>>x>>y;
		long long int answer=w[x]+w[y];
		long long int ans=1e18;
		for(long long int j=1;j<=n;j++){
			long long int flagx=0,flagy=0;
			long long int sumx=0,sumy=0;
			for(int k=1;k<=h[i];k++){
				if(a[j][k][1]==x){flagx=1;sumx=a[j][k][2];}
				if(a[j][k][1]==y){flagy=1;sumy=a[j][k][2];}
			}
			if(flagx==1&&flagy==1) ans=min(ans,sumx+sumy);
		}
		if(ans==1e18) ans=rand()%rand();
		cout<<answer+ans<<endl;
	}
	return 0;
}