#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,d;
int x[2000005];
int tor[2000005],tol[2000005];
int le[2000005][2],ri[2000005][2];//左边最远能到i的左端点，右端点 
int L[2000005],R[2000005];
void solve(){
	int ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++) le[i][0]=le[i][1]=n+1,ri[i][0]=ri[i][1]=0;
	int r=1;for(int i=1;i<=n;i++){
		while(r<n&&x[r+1]-x[i]<=d) r++;
		tor[i]=r;le[r][0]=min(le[r][0],i);le[r][1]=i;
	}
	int l=n;for(int i=n;i>=1;i--){
		while(l>1&&x[i]-x[l-1]<=d) l--;
		tol[i]=l;ri[l][0]=i;ri[l][1]=max(ri[l][1],i);
	}
	for(int i=1;i<=n;i++){
		L[i]=0;
		if(le[i][0]<=n) L[i]=L[le[i][0]]+le[i][1]-le[i][0]+1;
	}
	for(int i=n;i>=1;i--){
		R[i]=0;
		if(ri[i][1]) R[i]=R[ri[i][1]]+ri[i][1]-ri[i][0]+1;
	}
	for(int j=2;j<=n-2;j++){
		int l=le[j+1][0],r=ri[j][1];
		if(l>n||r==0||l==j||r==j+1||l==j+1||r==j) continue;
		int al=L[j+1],ar=R[j];
		if(tor[l-1]==j) al-=L[l];
		if(tol[r+1]==j+1) ar-=R[r];
		ans+=ar*al;
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--) solve();
	return 0;
}
