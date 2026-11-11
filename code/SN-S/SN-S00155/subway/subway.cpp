#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	bool t=false,u=false;
	int c,n,m,d,q,tz[10010],X,Y,l=0;
	ll a[10010],b[505],e[50010],f[50010],x[10010],y[10010];
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>a[i]; 
	}
	
	for(int i=0;i<n;i++){
		cin>>b[i];
		for(int j=0;j<b[i];j++){
			cin>>e[j+l]>>f[j+l];
		}
		l+=b[i];
	}

	for(int i=0;i<q;i++){
		cin>>x[i]>>y[i];
	}

	for(int i=0;i<q;i++){
		X=x[i];
		Y=y[i];
		tz[i]=a[X-1]+a[Y-1];
		cout<<tz[i]<<endl;
	}
	
	return 0;
}
