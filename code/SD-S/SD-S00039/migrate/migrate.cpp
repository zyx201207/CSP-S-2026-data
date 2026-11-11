#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+9;
const ll INF=3e18;
int Tid,T,n,X,Y,rt,vis[5009][5009];
ll d,x[N],ans,m;
void sol1()
{
	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)vis[i][j]=0;
	}
	for(int i=1;i<=n;i++){
		vis[i][i]=1;
		for(int l=i,r=i;l<=n;l=r){
			
			while(r<=n&&x[r]-x[l]<=d)r++;
			r--;
//			cerr<<i<<"  "<<l<<"  "<<r<<endl;
			if(l==r)break;
			for(int j=l+1;j<=r;j++){
				for(int k=0;k<3&&l-k>=i&&(x[j]-x[l-k])<=d;k++){
//					cerr<<i<<"          "<<j<<"  "<<l-k<<endl;
					vis[i][j]+=vis[i][l-k];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
//			cerr<<i<<"  "<<j<<"  "<<vis[i][j]<<"\n";
			if(vis[i][j]==2)ans++;
		}
	}
	cout<<ans<<"\n";
}
void sol2()
{
	if(n==1){
		cout<<0<<"\n";
		return;
	}
	m=d/(x[2]-x[1]);
	if(m<=1)cout<<"0\n";
	else{
		ans=max(n-2*m+1,0ll);
		cout<<ans<<"\n";
	}
}
void sol3()
{
	for(int i=1;i<=n;i++){
		if(x[i]-x[1]<=d&&x[n]-x[i]<=d){
			rt=i;
			break;
		}
	}
	ans=0;
	x[0]=-INF,x[n+1]=INF;
	X=upper_bound(x+1,x+n+1,x[rt-1]+d)-x-1;
	Y=upper_bound(x+1,x+n+1,x[rt-2]+d)-x-1;
	for(int i=1;i<rt;i++){
		if(x[rt+1]-x[i]>d){
			ans+=X-Y;
		}else{
			ans+=n-X;
		}
	}
	cout<<ans<<"\n";
}
void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	if(Tid<=10)sol1();
	else if(Tid<=12)sol2();
	else if(Tid<=14)sol3();
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>Tid>>T;
	while(T--)solve();
	return 0;
}
