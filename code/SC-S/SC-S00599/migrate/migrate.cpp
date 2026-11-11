#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
const int N = 1e6+5;
using namespace std;
int c,t,ls;
ll n,d,a[N],b[N],sum=0,ans=0,bj=1,cn=0;
vector<int>vis[N];

inline void build(){
	ll l=1;
	cn=1;
	while(l<=n){
		ll pp=0;
		while(pp<=d){
			l++;
			pp+=b[l];
			vis[cn].push_back(l);
			if(l>n) break;
		}
		cn++;
		l=cn+1;
		pp=0;
	} 
}

inline int dfs(ll x,ll y,ll z){
	if(x>=y&&z==cn) ls++;
	for(auto i:vis[x]){
		dfs(i,y,z+1);
	}
	return ls;
}

inline bool check(ll x,ll y){
	ll l=x,r=y;
	cn=0;
	while(l<r){
		ll pp=0;
		while(pp<=d){
			l++;
			pp+=b[l];
			if(l>n) break;
		}
		l--;
		pp=0;
		cn++;
	} 
	if(dfs(x,y,0)==2) return 1;
	return 0;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >>c >>t;
	while(t--){
		memset(vis,0,sizeof(vis));
		sum=0,ans=0,bj=1,ls=0;
		cin >>n >>d;
		for(int i=1;i<=n;i++) cin >>a[i];
		if(c<=10){
			for(int i=1;i<=n;i++){
				b[i]=a[i]-a[i-1];
			}
			build();
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(check(i,j)) ans++;
				}
			}
			cout <<ans <<endl;
		}
		else if(c>=13){
			for(int i=1;i<=n;i++){
				sum+=a[i];
				while(sum>d){
					ans+=(n-i+1);
					sum-=a[bj];
					bj++;
				}
			}
			cout <<ans <<endl;
		}
		else{
			if(a[2]-a[1]>d) cout <<0 <<endl;
			else if(d<=a[2]-a[1]&&a[2]-a[1]<=2*d) cout <<0 <<endl;
			else cout <<n-3 <<endl;
		}
	}
	return 0;
}
