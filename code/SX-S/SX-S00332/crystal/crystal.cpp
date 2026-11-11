#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int ans=0;
int b[N],bmx=-0x7fffffff,bmn=0x7fffffff;
int c[N];
void Solve(){
	cin>>n>>m;
	c[0]=0;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		c[i]=c[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=a[i]-a[i-1];
	
	b[1]=b[2];
	for(int i=1;i<=n;i++) {
		bmx=max(bmx,abs(b[i]));
		bmn=min(bmn,abs(b[i]));
	}
	//for(int i=1;i<=n;i++) cerr<<c[i]<<' ';
	//cerr<<'\n';
	//cerr<<bmx<<' '<<bmn<<'\n';
	if(bmx==bmn){
		if(bmx==0){
			cout<<n;
			return ;
		}
		//cerr<<"p1\n";
		int cha=bmx,i=1;
		while(m>0){
			
			m-=i*abs(cha);
			i++;
			//cerr<<m<<'\n';
		}//
		if(m==0) ans=i;
		else ans=i-1;
		if(ans<=n) cout<<ans;
		else cout<<n;
	}
	else{
		int mx=-0x7fffffff;
		for(int i=n;i>=2;i--){
			for(int j=i-1;j>=1;j--){
				//cerr<<i<<' '<<j<<' '<<abs(c[i]-c[j])+b[i+1]<<'\n';
				if(abs(c[i]-c[j])<=m) {
					//i-j+1
					mx=max(mx,i-j+1);
				}
			}
		
		}
		cout<<mx;
	}
	return ;
}
signed main(){
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int t=1;
	//cin>>t;
	while(t--) Solve();
	return 0;
}//30