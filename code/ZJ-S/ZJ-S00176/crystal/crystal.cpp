#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll n,m;
ll a[N];
ll qz[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		qz[i]=qz[i-1]+(a[i]-a[i-1])*(i-1);
	}
	ll tmp=0;
	int ans=0;
	int i=1,j=1;
	while(i<=n){
		tmp=qz[i]-qz[j]-(j-1)*(a[i]-a[j]);
		if(tmp>m){
			j++;
		}else{
			ans=max(ans,i-j+1);
			i++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
