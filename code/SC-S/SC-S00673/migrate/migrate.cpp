#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
typedef long long ll;
ll a[N];
ll f[N],cnt_minf[N];
void solve(){
	ll n,d;cin>>n>>d;
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++)cin>>a[i];
	ll cnt_double=0;
	for(int j=1;j<n;j++){
		memset(f,0x3f3f3f3f,sizeof(f));
		memset(cnt_minf,0,sizeof(cnt_minf));
		f[j]=0;
		for(int i=j+1;i<=n;i++){
			int k=j;
			while(k<i&&a[k]+d<a[i])k++;
			if(k==i)continue;
			for(int p=k;p<=i-1;p++){
				if(f[p]+1==f[i])cnt_minf[i]++;
				else if(f[p]+1<f[i]){
					f[i]=f[p]+1;
					cnt_minf[i]=1;
				}
			}
		}
		for(int i=j+1;i<=n;i++){
			if(cnt_minf[i]==2)cnt_double++;
			//cout<<f[i]<<" "<<cnt_minf[i]<<"  ";
		}
		//cout<<'\n';
	}
	cout<<cnt_double<<"\n";
	return ;
}
void solve2(){
	ll n,d;cin>>n>>d;
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++)cin>>a[i];
	ll cnt_double=0;
	for(int j=1;j<n;j++){
		memset(f,0x3f3f3f3f,sizeof(f));
		memset(cnt_minf,0,sizeof(cnt_minf));
		f[j]=0;
		for(int i=j+1;i<=n;i++){
			int k=j;
			while(k<i&&a[k]+d<a[i])k++;
			if(k==i)continue;
			for(int p=k;p<=i-1;p++){
				if(f[p]+1==f[i])cnt_minf[i]++;
				else if(f[p]+1<f[i]){
					f[i]=f[p]+1;
					cnt_minf[i]=1;
				}
			}
		}
		for(int i=j+1;i<=n;i++){
			if(cnt_minf[i]==2)cnt_double++;
			//cout<<f[i]<<" "<<cnt_minf[i]<<"  ";
		}
		//cout<<'\n';
	}
	cout<<cnt_double;
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t>1){
		solve();
		t--;
	}
	solve2();
	return 0;
}