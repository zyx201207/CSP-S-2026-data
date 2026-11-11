#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e6+5;
const ll M=1e14+5;

ll n,m,c;
ll a[N];
map<int,int> mp;

void dfs(ll l,ll r, ll s){
	if(l>r){return;}
	if(l==r){
		mp[s]++;
		return;
	}
	for(int i=l+1;i<=r;i++){
		if(a[i]-a[l]<=m){
			dfs(i,r,s+1);
		}
		else{
			break;
		}
	}
}

bool check(int l,int r){
	mp.clear();
	if(l>r){swap(l,r);}
	
	dfs(l,r,0);
	
	ll s1=M,s2=0;
	for(auto t:mp){
		if(t.first<s1){
			s1=t.first;
			s2=t.second;
		}
	}
	return (s2==2);
}

void A(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	if(n==1){
		cout<<"0\n";
		return;
	}
	if(n<=9){
		ll ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				ans+=check(i,j);
			}
		}
		cout<<ans<<"\n";
	}
	else{
		int len=a[2]-a[1];
		if(len==0){
			cout<<"0\n";
		}
		else if(len>m){
			cout<<"0\n";
		}
		else if(len==m){
			cout<<n-1<<"\n";
		}
		else if(len<m){
			int t=m/len;
			if(t==0){
				cout<<"0\n";
			}
			else{
				cout<<n/t<<"\n";
			}
		}
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int t;
	cin>>c>>t;
	while(t--){A();}
	return 0;
}