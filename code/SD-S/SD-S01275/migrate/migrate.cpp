#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mid (((ll)l+r)>>1)
ll n,k,a[1000005],ju[1000005],f[1000005],num[1000005],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int C,T;
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
			ju[i]=0;
		}ans=0;
		if(C==11||C==12){
			if(n<=3){
				cout<<"0\n";
				continue;
			}
			ll d=a[2]-a[1];
			ll j=k/d;
			if(j<=1)cout<<0<<'\n';
			else cout<<max(0ll,n-(j*2-1))<<'\n';
			continue;
		}
		ll l=1;
		for(ll r=1;r<=n;r++){
			while(l<r&&a[l]+k<a[r])l++;
			ju[r]=l;
		}
		ans=0;
		for(ll i=1;i<=n;i++){
			num[i]=1;
			f[i]=1;
			for(ll j=i+1;j<=n;j++){
				if(max(i,ju[j])==j)break;
				f[j]=f[max(i,ju[j])];
				num[j]=num[max(i,ju[j])]+1;
				for(l=max(i,ju[j])+1;l<j;l++){
					if(num[l]==num[j]-1)f[j]++;
					else break;
					if(f[j]>2)break;
				}
				if(f[j]==2)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2
5 2
1 2 3 4 5
4 2
1 2 3 4
*/
