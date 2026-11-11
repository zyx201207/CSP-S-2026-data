#include<bits/stdc++.h>
using namespace std;
#define int long long 
int c,t,n,d,x[2000006],sl[2000005],sr[2000005],lsum[2000005],rsum[2000005];
void mian(){
	cin>>n>>d;
//	cout<<n<<' '<<d<<'\n';
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	if(n<=3){
		cout<<0<<'\n';
		return;
	}
	sl[1]=0;
	sr[1]=0;
	int ans=0;
	for(int i=1,b=1,k=1;i<=n;i++){
		b=k;
		if(i==n) sl[i]=sl[b]+i-b;
		else{
			while(x[i+1]-x[k]>d&&k<=n) k++;
			sl[i]=(x[i+1]-x[b]<=d)?1:(sl[b]+k-b);
		} 
	}
	for(int i=n,b=n,k=n;i>0;i--){
		b=k;
		if(i==1) sr[i]=sr[b]+b-i;
		else{
			while(x[k]-x[i-1]>d&&k>0) k--;
			sr[i]=(x[b]-x[i-1]<=d)?1:(sr[b]+b-k);
		}
	}
	for(int i=1;i<=n;i++){
		lsum[i]=lsum[i-1]+sl[i];
		rsum[i]=rsum[i-1]+sr[i];
//		cout<<sl[i]<<' '<<sr[i]<<'\n';
	}
	int lu=1,ru=1,lv=1,rv=3;
	while(x[2]-x[lu]>d) lu++;
	ru=lu;
	for(int i=1;i<=n;i++){
		lu=ru;
//		cout<<'!';
		while(x[i+2]-x[ru]>d&&ru<=i-1) ru++;
//		cout<<'!';
//		while(x[lv]-x[i-1]<=k) lv++;
		lv=rv;
//		cout<<'!';
		while(x[rv]-x[i]<=d&&rv<=n) rv++;
//		cout<<'!';
		if(ru<=i&&lv>=i+2&&lu<ru&&lv<rv){
//			cout<<lu<<' '<<ru<<' '<<i<<' '<<lv<<' '<<rv<<'\n';
//			cout<<(lsum[ru-1]-lsum[lu-1])*(rsum[rv-1]-rsum[lv-1])<<'\n';
			ans+=(lsum[ru-1]-lsum[lu-1])*(rsum[rv-1]-rsum[lv-1]);
		}
//		cout<<'!';
	}
//	cout<<'!';
	cout<<ans<<'\n';
}
signed main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) mian();
	return 0;
} 
