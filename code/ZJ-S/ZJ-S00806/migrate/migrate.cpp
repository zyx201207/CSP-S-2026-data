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
	
const int N=2e6+5;
int n,d,a[N],nxt[N],f[N][3],ans;

void solve(){
	cin>>n>>d;
	rp(i,1,n)
		cin>>a[i];
	ans=0;
	rp(i,1,n){
		int pos=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
		nxt[i]=pos;
	}
	pr(i,n,2){
		if(nxt[i]==i){
			f[i][0]=0;
			f[i][1]=0;
			f[i][2]=0;
		}else{
			int j=nxt[i];
			if(abs(a[i-1]-a[j])>d){
				int k=max(nxt[i-1],i);
				f[i][0]=f[j][0]+j-k;
			}else f[i][0]=0;
			if(abs(a[i-1]-a[j])>d){
				int k=max(nxt[i-1],i);
				if(j-k>=2)f[i][1]=f[j][2];
				else f[i][1]=f[j][1];
			}else f[i][1]=0;
			if(abs(a[i-1]-a[j])>d){
				int k=max(nxt[i-1],i);
				if(j-k>=2)f[i][2]=f[j][2];
				else f[i][2]=f[j][1];
				int l=max(nxt[i-2],i);
				f[i][2]+=k-l;
			}else{
				int l=max(nxt[i-2],i);
				if(l<j)f[i][2]=f[j][0]+j-l;
				else f[i][2]=0;
			}
		}
//		cerr<<i<<" "<<f[i][0]<<" "<<f[i][1]<<" "<<f[i][2]<<"\n";
	}
	rp(i,1,n){
		int j=nxt[i];
		if(j-i==1)ans+=f[j][1];
		else if(j-i>1)ans+=f[j][2];
//		cerr<<ans<<"\n";
	}
	cout<<ans<<"\n";
	return;
}
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,_=1;cin>>c>>_;
	while(_--)SOLVE::solve();
	return 0;
}
