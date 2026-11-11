#include<bits/stdc++.h>
#define endl '\n';
using namespace std;
#define int long long
const int N=2000005;
int n,d,aa[N],ans,a[N],nxtl[N],nxtr[N],suml[N],sumr[N];
void solve(int LL,int RR){
	int n=RR-LL+1;
	for(int i=1;i<=n;i++) a[i]=aa[i-1+LL];
	for(int i=1,r=1;i<=n;i++){
		while(r<n&&a[r+1]-a[i]<=d) r++;
		nxtr[i]=r;
	}
	for(int i=n,l=n;i>=1;i--){
		while(l>1&&a[i]-a[l-1]<=d) l--;
		nxtl[i]=l;
	}
	sumr[n]=0;
	for(int i=n-1;i>=2;i--){
		if(nxtr[i]==nxtr[i-1]) sumr[i]=0;
		else{
			sumr[i]=sumr[nxtr[i]];
			sumr[i]+=nxtr[i]-nxtr[i-1];
		}
	}
	suml[1]=0;
	for(int i=2;i<=n-1;i++){
		if(nxtl[i]==nxtl[i+1]) suml[i]=0;
		else{
			suml[i]=suml[nxtl[i]];
			suml[i]+=nxtl[i+1]-nxtl[i];
		}
	}
	for(int x=2,y;x<=n-2;x++){
		y=x+1;
		if(nxtr[x]==nxtr[x-1]||nxtl[y]==nxtl[y+1]) continue;
		int a=(nxtl[y+1]-nxtl[y]-(nxtl[y+1]==y?1:0)),b=(nxtr[x]-nxtr[x-1]-(nxtr[x-1]==x?1:0));
		ans+=a*b;
		if(nxtl[x]==nxtl[y]) ans+=suml[nxtl[x]]*b;
		if(nxtr[x]==nxtr[y]) ans+=sumr[nxtr[y]]*a;
		if(nxtl[x]==nxtl[y]&&nxtr[x]==nxtr[y]) ans+=suml[nxtl[x]]*sumr[nxtr[y]];
	}
}
void Solve(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>aa[i];
	int lst=0;
	for(int i=1;i<n;i++) if(aa[i]+d<aa[i+1]) solve(lst+1,i),lst=i;
	solve(lst+1,n);
	cout<<ans<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--) Solve();
	return 0;
}
