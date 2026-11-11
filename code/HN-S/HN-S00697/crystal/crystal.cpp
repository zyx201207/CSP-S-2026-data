#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+3;
const ll INF = 1e18;
ll n,m;
ll a[N];
ll b[N];

int check_max(int l,int r){
	ll maxx=-INF;
	for(int i=l;i<=r;i++){
		maxx=max(maxx,a[i]);
	}
	return maxx;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	int flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+a[i];
		if(a[i]!=i) flag=0;
	}
	if(n<=1000){
		for(int i=n;i>=1;i--){
			for(int j=1;j+i-1<=n;j++){
				int len=i+j-1;
				ll sum=check_max(j,len)*i;
				//cout<<i<<" "<<j<<" "<<sum<<"\n";
				if(sum<=b[len]-b[j-1]+m){
					cout<<i;
					return 0;
				}
			}
		}
	}else{
		for(int i=n;i>=1;i--){
			if(check_max(1,i)*i<=b[i]+m) {
				cout<<i;
				return 0;
			}
		}
	}
	return 0;
}
