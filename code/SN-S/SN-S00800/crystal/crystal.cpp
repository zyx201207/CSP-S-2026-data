#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vec vector
#define pb push_back
const int N=5e5+100;
const int Log=20;
int n;
ll a[N],m;
ll tot[N];
ll st[Log][N];
ll lg[N];
inline void build(){
	for(int i=1;i<=n;i++) st[0][i]=a[i];
	for(int j=1;j<Log;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			st[j][i]=max(st[j-1][i],st[j-1][i+(1<<(j-1))]);
		}
	}
	lg[1]=0;
	for(int i=2;i<=n;i++) lg[i]=lg[i/2]+1;
}
inline ll get(int l,int r){
	int k=lg[r-l+1];
	return max(st[k][l],st[k][r-(1<<k)+1]);
}
inline void Solve(){
	cin>>n>>m;
	bool v=true;
	cin>>a[1]>>a[2];
	ll d=a[2]-a[1];
	for(int i=3;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]!=d) v=false;
	}
	if(v){
		ll k=m;
		int cnt=0;
		ll ans=0;
		for(int i=n-1;i>=1;i--){
			ll col=(++cnt)*d;
			if(k-col>=0){
				k-=col;
				ans++; 
			}else break;
		}
		cout<<ans+1<<"\n";
		return;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) tot[i]=tot[i-1]+a[i];
	build();
	ll ans=-1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int num=j-i;
			ll col=get(i,j)*num-(tot[j-1]-tot[i-1]);
			if(col<=m){
				int len=j-i+1;
				if(ans<len){
					ans=len;
				}
			} 
		}
	}
	cout<<ans<<"\n";
	return;
} 
/*
5 5 
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int _=1;
	//cin>>_;
	while(_--) Solve();
	return 0;
}
