#include<iostream>
#define ll long long
using namespace std;
ll n, m, a[500010], q[500010], num[500010];
bool checkA(){
	for(ll i=1;i<=n;i++){
		if(a[i]<a[i-1]) return 0;
	}
	return 1;
}
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	if(checkA()){
		for(ll i=1;i<=n;i++) num[a[i]]=i;
		for(ll i=1;i<=m;i++){
			if(i==1) cout<<num[i];
			else cout<<' '<<num[i];
		}
	}else{
		for(ll i=1;i<=n;i++){
			ll tt=1;
			for(ll j=i;j<=n;j++){
				q[tt]=a[j];
				for(ll z=1;z<tt;z++){
					if(q[z]==q[tt]){tt=z;break;}
				}
				tt++;
			}
			for(ll j=1;j<tt;j++) num[q[j]]++;
		}
		for(ll i=1;i<=m;i++) cout<<num[i]<<' ';	
	}
	return 0;
} 
