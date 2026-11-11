#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n;
		ll dis;
		cin>>n>>dis;
		vector<ll> A(n+1);
		for(int i=1;i<=n;i++)
			cin>>A[i];
		vector<int> vis(n+1);
		ll ans=0;
		for(int i=1;i<=n;i++){
			if(vis[i])  continue;
			vector<int> d;
			d.pb(0);
			int m=0,p=i;
			vis[p]=1;
			d.pb(p),m++;
			while(p!=n){
				int t=upper_bound(A.begin()+1,A.end(),A[p]+dis)-A.begin()-1;
				if(vis[t])  break;
				p=t,vis[t]=1,d.pb(p),m++;
			}
			vector<int> td(m+1);
			int t1=1,t2=0;
			for(int j=2;j<=m;j++){
				if(d[j]-1==d[j-1]){
					td[j]=2;
					continue;
				}
				ll v1,v2=A[d[j]-1];
				bool flag=0;
				if(d[j]-2==d[j-1])  flag=1;
				else  v1=A[d[j]-2];
				int p1,p2;
				if(!flag)  p1=upper_bound(A.begin()+1,A.end(),v1+dis)-A.begin()-1;
				p2=upper_bound(A.begin()+1,A.end(),v2+dis)-A.begin()-1;
				int r;
				if(j==m)  r=upper_bound(A.begin()+1,A.end(),A[d[j]]+dis)-A.begin()-1;
				else  r=d[j+1];
				ans+=1ll*t1*(p2-(flag?d[j]+1:p1))+1ll*t2*(r-p2);
				if(p1==d[j+1])  td[j+1]=0;
				else if(p2==d[j+1])  td[j+1]=1;
				else  td[j+1]=2;
				if(td[j]==0)  t1=1,t2=0;
				else if(td[j]==1)  t2=t1+1,t1=0;
				else  t1++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}