#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define max(a,b) (a>b)?a:b
ll C,T,n,d,x[2000004],ans;
pair<ll,ll> p[5004][5004];
vector<ll> a(5004);
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		if(C==11||C==12){
			ll dis=x[2]-x[1];
			d/=dis;
			if(d<2){
				cout<<"0\n";
				continue;
			}
			d+=d-1;
			if(n-d>0)
				cout<<n-d<<"\n";
			else
				cout<<"0\n";
			continue;
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(x[j]-x[i]<=d){
					p[i][j].fi=1;
					p[i][j].se=1;
				}
				else{
					p[i][j].fi=1e18;
					p[i][j].se=0;
				}
		for(int len=1;len<=n;len++){
			for(int i=1;i<=n-len+1;i++){
				int j=i+len-1;
				if(p[i][j].fi==1) continue;
				ll s=1e18;
				for(int k=i+1;k<j;k++){
					if(!p[i][k].se||!p[k][j].se) continue;
					if(p[i][k].fi+p[k][j].fi<s) s=p[i][k].fi+p[k][j].fi;
				}
				p[i][j].fi=s;
				if(s==1e18) continue;
				for(int k=i+1;k<j;k++){
					if(!p[i][k].se||!p[k][j].se) continue;
					if(p[i][k].fi+p[k][j].fi==s) p[i][j].se+=p[i][k].se*p[k][j].se;
				}
				if(p[i][j].se==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}