#include<bits/stdc++.h>
#define ll long long
#define N 1000005
#define M 5005
using namespace std;
ll c,n,m,d,q,w[N],a[M][M],t[M][M],x[N],y[N],l[M][M];
bool is[M][M];
vector<ll>v[N];
void P20acsh(){
	for(int i=1;i<=n;i++){
		is[a[i][1]][a[i][2]]=true;
		is[a[i][2]][a[i][1]]=true;
		l[a[i][1]][a[i][2]]=t[i][1]+t[i][2];
		l[a[i][2]][a[i][1]]=t[i][1]+t[i][2];
	}
}
void P20a(ll x,ll y){
	ll step[M][M];
	if(is[x][y]==true){
		cout<<l[x][y];
		return;
	}
	
	else{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			step[i][j]=step[j][i]=1e9;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=i;j++)
				for(int p=1;p<=j;p++){
					if(is[i][j]==true&&is[j][p]==true){
						step[i][p]=step[p][i]=min(step[i][p],min(step[p][i],step[i][j]+step[j][p]));
					}
				}
		cout<<w[x]+step[x][y]+w[y];
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	bool isa=true;
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++)cin>>a[i][j]>>t[i][j];
		if(k>2)isa=false;
	}
	if(isa){
		P20acsh();
		while(q--){
			ll x,y;
			cin>>x>>y;
			P20a(x,y);
		}
	}
	else {
		while(q--)cout<<0;
	}
	return 0;
}
