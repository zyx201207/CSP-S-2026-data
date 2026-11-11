#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
ll n,m,a[N],b[N][40],c[N],ans;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		c[i]=a[i];
	}
	sort(c+1,c+1+n,cmp);
	sort(a+1,a+1+n,cmp);
	for(ll i=1;i<=n;i++){
		ll cnt=32;
		while(a[i]>0){
			b[i][cnt--]=(a[i]%2);
			a[i]/=2;
		}
	}
	for(ll i=1;i<=32;i++){
		ll cnt=0;
		for(ll g=1;g<=n;g++){
//			cout<<b[g][i];
			if(b[g][i]==1){
				cnt++;
			}
		}
//		cout<<'\n';
		if(cnt>=m){
			cnt=1;
			bool f=1;
			for(ll g=1;g<=n;g++){
//				cout<<c[g]<<' '<<ans<<'\n';
				if(cnt==m){
					cout<<ans;
					return 0;
				}
				if(b[g][i]==1&&f){
					ans=c[g];
					f=0;
					continue;
				}
				if(b[g][i]==1){
					ans&=c[g];
					cnt++;
				}
			}
		}
	}
//	cout<<ans;
	return 0;
}
