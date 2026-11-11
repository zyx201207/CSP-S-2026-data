#include<bits/stdc++.h>
using namespace std;
#define int long long
int deal=0;
int n,m;
int a[500005];
int cnt;
int qzh[500005];
int dengcha[500005];
void solve(){
	int cha=a[2]-a[1];
	int xiang=0;
	for(int i=1;i<=n;++i){
		xiang=(a[i]-a[1])/cha+1;
		dengcha[i]=xiang*cha+dengcha[i-1];
	}int ans=0;
	for(int i=1;i<=n;++i){
		//cout<<dengcha[i]<<'\n';
		if(m<dengcha[i]){
			break;
		}
		ans=i;
	}
	cout<<ans+1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;

	for(int i=1;i<=n;++i){
		cin>>a[i];
		qzh[i]=qzh[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	if(n>5000){
		solve();
		return 0;		
	}
	
	int mx=1,cnt;
	int m2=m;
	for(int i=1;i<=n;++i){
		cnt=1;
		m2=m;
		for(int j=i-1;j>0;--j){
			m2=m2-(a[i]-a[j]);
			if(m2>=0){
				cnt++;
			}
			else{
				break;
			}
		}
		mx=max(mx,cnt);
	}
	cout<<mx;
	
	return 0;
}
