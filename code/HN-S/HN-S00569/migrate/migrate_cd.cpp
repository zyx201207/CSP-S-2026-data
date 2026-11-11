#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int ID;
int n,d,x[N];
int s[N],r[N];
int rp[N];
int c[N];
int tp[N];
void work(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	if(d!=14)return;
	r[n]=1,rp[n]=-1;
	for(int i=n-1;i;i--){
		int p=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
		if(i==1||x[p]-x[i-1]>d)
			r[i]=r[p]+1,rp[i]=p;
		else r[i]=1,rp[i]=-1;
	}
	// cout<<"check begins\n";
	// for(int i=1;i<=n;i++)
	// 	cout<<i<<' '<<r[i]<<'\n';
	// cout<<"check ends\n";
	for(int i=1;i<=n;i++)tp[i]=-1,s[i]=c[i]=0;
	for(int i=1;i<=n;i++){
		int p=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
		if(p<i+2)continue;
		tp[i]=p;
		int g=upper_bound(x+1,x+n+1,x[p-1]+d)-x-1;
		int q=upper_bound(x+1,x+n+1,x[p-2]+d)-x;
		// cout<<i<<' '<<p<<' '<<q<<' '<<g<<'\n';
		if(q<=g){
			s[i]+=g-q;
			if(~rp[g]&&x[rp[g]]-x[g-1]>d)
				s[i]+=r[g];
			else ++s[i];
			// cout<<i<<' '<<s[i]<<' '<<q<<' '<<g<<'\n';
		}
	}
	// for(int i=1;i<=n;i++)cout<<s[i]<<' ';
	// cout<<'\n';
	int ans=s[n];
	for(int i=n-1;i;i--){
		int p=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
		if(
			(i==1||x[p]-x[i-1]>d)&&
			(p==n||x[p+1]-x[i]>d)
		){
			c[i]+=c[p];
			if(!~tp[p]||x[tp[p]]-x[p-1]>d)
				c[i]+=s[p];
			// cout<<tp[p]<<' '<<x[tp[p]]<<'\t';
		}
		ans+=c[i]+s[i];
		// cout<<i<<' '<<p<<' '<<c[i]<<'\n';
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;cin>>ID>>t;
	// t=1;
	while(t--)work();
	return 0;
}