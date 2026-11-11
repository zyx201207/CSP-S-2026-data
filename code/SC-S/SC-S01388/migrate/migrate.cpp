#include<bits/stdc++.h>
#define frein(x) freopen(x".in","r",stdin)
#define freout(x) freopen(x".out","w",stdout)
#define cinios cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
const int N=5e5+10;
int a[N];
int n,d;
void dencha(int x){
	if(x>=d){
		cout<<0;
		return ;
	}
	int ans=0;
	int k=d/x;
	for(int i=1;i<=n;i++){
		if(a[i]+k+1<=a[n]) ans++;
	}
	cout<<ans<<"\n";
}
void solve(){
	cin>>n>>d;
	int x=0;
	int f1=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i<=2) x=a[i]-a[i-1]; 
		if(x!=a[i]-a[i-1]) f1=0;
	}
	if(f1) dencha(x);
	else{
		cout<<n<<"\n";
	}
}
int main(){
	frein("migrate");
	freout("migrate");
	cinios;
	int c,T;cin>>c>>T;
	while(T--) solve();
	return 0;
}