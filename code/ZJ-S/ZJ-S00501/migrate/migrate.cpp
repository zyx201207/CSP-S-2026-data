#include<bits/stdc++.h>
using namespace std;
#define ft first
#define sd second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vel;
typedef vector<vel> vevel;
typedef vector<pll> velp;
typedef vector<velp> vevelp;
typedef vector<bool> veb;
typedef string sig;
typedef priority_queue<ll> pql;
const ll MAXN=1e18;
void slv1(){
	ll n,d;
	cin>>n>>d;
	vel v(n+3);
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	if(n==1){
		cout<<"0\n";
		return;
	}
	vel far(n+3);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(v[j]-v[i]<=d){
				far[i]=j;
//				cout<<"!";
			}
		}
//		cout<<far[i]<<' ';
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ll cnt=0;
			for(int k=i;k<j;k=far[k]){
				if(far[k]<=j){
					if(k-1>=i&&far[k]==far[k-1]){
						cnt++;
						if(k-2>=i&&far[k]==far[k-2]){
							cnt++;
						}
					}
				}else{
					if(k-1>=i&&far[k-1]>=j){
						cnt++;
						if(k-2>=i&&far[k-2]>=j){
							cnt++;
						}
					}
				}
				if(far[k]==k){
					cnt+=100;
					break;
				}
			}
			if(cnt==1){
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
}
void slv2(){
	ll n,d;
	cin>>n>>d;
	vel v(n+3);
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	if(n==1){
		cout<<"0\n";
		return;
	}
	ll x=v[2]-v[1];
	ll tmp1=d/x;
	if(tmp1==1){
		cout<<"0\n";
	}else{
		cout<<n-tmp1-1<<'\n';
	}
}
void slv3(){
	ll n,d;
	cin>>n>>d;
	vel v(n+3);
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	if(n==1){
		cout<<"0\n";
		return;
	}
	ll x=0;
	for(int i=1;i<=n;i++){
		if(v[i]-v[1]<=d&&v[n]-v[i]<=d){
			x=i;
			break;
		}
	}
	ll l,r;
	ll sum=v[x+1]-v[x],ans=0;
	for(l=x-1;l>=1;l--){
		sum+=v[l+1]-v[l];
		if(sum>d){
			sum-=v[l+1]-v[l];
			l++;
			break;
		}
	}
	if(sum+v[x+2]-v[x+1]<=d){
		ans++;
	}else{
		ans+=n-x;
	}
	sum=v[x]-v[x-1];
	for(r=x+1;r<=n;r++){
		sum+=v[r+1]-v[r];
		if(sum>d){
			sum-=v[r+1]-v[r];
			r--;
			break;
		}
	}
	if(sum+v[x+2]-v[x+1]<=d){
		ans++;
	}else{
		ans+=n-x;
	}
	cout<<ans<<'\n';
}
void slv4(){
	ll n,d;
	cin>>n>>d;
	vel v(n+3);
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	if(n==1){
		cout<<"0\n";
		return;
	}
	cout<<n*(n-1)/2<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll T=1,c;
	cin>>c>>T;
	while(T--){
		if(c<=10){
			slv1();
		}else if(c>10&&c<=12){
			slv2();
		}else if(c>12&&c<=14){
			slv3();
		}else{
			slv4();
		}
	}
	return 0;
}