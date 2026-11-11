#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,T,n,d,i,x[2000010],j,ans,ji,mi;
vector <int> a[100010];
void sc(int t,int y,int s){
	int i;
	if(t==y){
		if(s<mi) mi=s,ji=1;
		else if(s==mi) ji++;
		return ;
	}
	for (i=0;i<a[t].size();i++)
		sc(a[t][i],y,s+1);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;ans=0;
		for (i=1;i<=n;i++) cin>>x[i];
		for (i=1;i<=n;i++)
			for (j=i+1;j<=n;j++)
				if(1LL*(x[j]-x[i])<=d) a[i].push_back(j);
				else break;
		for (i=1;i<n;i++)
			for (j=i+1;j<=n;j++){
				mi=2e18+1;
				ji=0;
				sc(i,j,0);
				if(ji==2) ans++;
			}
		cout<<ans<<"\n";
		for (i=1;i<=n;i++)
			while(a[i].size())
				a[i].pop_back();
	}
	return 0;
}
