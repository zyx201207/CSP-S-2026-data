#include<bits/stdc++.h>

using namespace std;

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

const int N=2e5+5;
int n,m,a[N],g[N],ans;

void solve(){
	cin>>n>>m;
	rp(i,1,n)
		cin>>a[i],g[i]=true;
	pr(i,30,0){
		int cnt=0;
		rp(j,1,n){
			if(!g[j])continue;
			if((a[j]>>i)&1)cnt++;
		}
		if(cnt>=m){
			rp(j,1,n)
				if(g[j]&&((a[j]>>i)&1)==0)g[j]=false;
			ans+=(1<<i);
		}
	}
	cout<<ans<<"\n";
	return;
}

}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int _=1;//cin>>_;
	while(_--)SOLVE::solve();
	return 0;
}
