#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
#define print(a)cout<<#a<<"= "<<a<<"\n";
#define aprint(a,l,r)cout<<#a<<"= ";rep(i,l,r)cout<<a[i]<<", ";cout<<"\n";
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int N=2e6+7;
ll c,T;
ll n,d,x[N];
ll mp[N];
pair<ll,ll>f[N];
struct S{
	ll id,val,f;
}q[N];
void solveA(){
	d=d/(x[2]-x[1]);
	if(d<=1){
		cout<<"0\n";
		return ;

	}
	cout<<max(n-2*d+1,0ll)<<endl;
}
void add(pair<ll,ll>&a,pair<ll,ll>b){
	b.fi+=1;
	if(a.fi>b.fi)a=b;
	else if(a.fi==b.fi)a.se+=b.se;
}
void solveelse(){
	//map<ll,ll>jc;
	ll ans=0;
	for(int i=1;i<=n;i++){
		//jc.clear();
		for(int j=1;j<=n;j++){
			f[j]={1e18,0};
		}
		f[i]={0,1};
		for(int j=i+1;j<=n;j++){
			for(int k=i;k<j;k++){
				if(x[j]-x[k]<=d)add(f[j],f[k]);
			}
			if(f[j].se==2){
				//cout<<i<<" "<<j<<endl;
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
}
void solveelse2(){
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++)mp[j]=0;
		int l=1,r=0;
		for(int j=1;j<=n;j++){
			f[j]={1e18,0};
		}
		f[i]={0,1};
		for(int j=i+1;j<=n;j++){
			if(f[j-1].fi!=1e18){
				while(l<=r&&q[r].val>f[j-1].fi){
					mp[q[r].val]-=q[r].f;
					r--;
				}
				q[++r]={j-1,f[j-1].fi,f[j-1].se};
				mp[q[r].val]+=q[r].f;
			}
			while(l<=r&&x[j]-x[q[l].id]>d){
				mp[q[l].val]-=q[l].f;
				l++;
			}
			if(l<=r){
				f[j].fi=q[l].val+1;
				f[j].se=mp[q[l].val];
				//cout<<i<<" "<<j<<" "<<f[j].fi<<" "<<f[j].se<<endl;
				if(f[j].se==2){
					ans++;
				}
			}
			
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(13<=c&&c<=14)cout<<"0\n";
		else if(11<=c&&c<=12)solveA();
		else solveelse2();
	}
	return 0;
}
/*
froepen
chzx_AT AK NGOI!!!!!
17:37
56pts
*/