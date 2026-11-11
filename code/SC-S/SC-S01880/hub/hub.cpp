#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,k,x,y,z;
const int N=1e6+10;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ll v[N];
		cin>>n>>k;
		for(int i=1;i<=n;i++)cin>>x>>y;
		v[x]++;v[y]++;
		sort(v,v+N-1,getchar());
		ll i=0;
		while(z<=k){
			z+=v[i];
			i++;
		}
		i/=2;
		i*=log(i);
		cout<<i<<'\n';
	}
	return 0;
}
