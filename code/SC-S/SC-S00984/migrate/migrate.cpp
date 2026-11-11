#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
int c,t,n;
ll x[N],d;
int f[N];
int suan(int l,int r){
	memset(f,0x3f,sizeof(f));
	f[l]=0;
	int res=0;
	for(int i=l+1;i<=r;i++){
		bool fh=false;
		for(int j=i-1;j>=l&&(x[i]-x[j]<=d);j--){
			fh=true;
			if(f[i]==f[j]+1){
				res++;
			}
			else if(f[i]>f[j]+1){
				f[i]=f[j]+1;
				res=1;
			}
		}
		if(!fh) return 0;
	}
	return res;
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	int ans=0;
	if(c==11||c==12){
		ll cha=x[2]-x[1];
		ll j=cha;
		while(j+cha<=d) j+=cha;
		for(int i=cha;i<j;i+=cha){
			int k=i+j;
			if(k/cha+1<=n) ans+=(n-k/cha)*2;
		}
		cout<<ans<<"\n";
		return;
	}
	for(int i=1;i+3<=n;i++){
		for(int j=i+3;j<=n;j++){
			if(suan(i,j)==2) ans++;
		}
	}
	cout<<ans<<"\n";
	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}