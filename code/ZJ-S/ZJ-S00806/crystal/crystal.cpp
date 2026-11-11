#include<bits/stdc++.h>

using namespace std;

#define int long long

#define rp(i,j,k) for(int i=(j);i<=(k);i++)
#define pr(i,j,k) for(int i=(j);i>=(k);i--)
#define vi vector<int>
#define pii pair<int,int>
#define eb emplace_back
#define fi first
#define se second
void gmin(int &x,int y){x=min(x,y);}
void gmax(int &x,int y){x=max(x,y);}

namespace SOLVE{

const int N=5e5+5;
int n,m,a[N];

void solve(){
	cin>>n>>m;
	rp(i,1,n)
		cin>>a[i];
	sort(a+1,a+n+1);
	int i=0,j=1,sum=0,ans=0;
	while(i<n){
		i++;sum+=a[i];
		while(j<=i&&a[i]*(i-j+1)-sum>m)
			sum-=a[j],j++;
		gmax(ans,i-j+1);
	}
	cout<<ans<<"\n";
	return;
}
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int _=1;//cin>>_;
	while(_--)SOLVE::solve();
	return 0;
}