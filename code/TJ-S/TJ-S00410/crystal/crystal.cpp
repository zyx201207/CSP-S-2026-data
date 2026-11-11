#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500005;
ll n,m,a[N];
ll read(){
	ll k=0,mu=1;
	char c;
	while(true){
		c=getchar();
		if(c<45){
			break;
		}
		if(c=='-'){
			mu=-1;
			continue;
		}
		k=(k<<1)+(k<<3)+(c^48);
	}
	return k*mu;
}
map<ll,int>q,l;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	getchar();
	for(int i=1;i<=n;i++){
		a[i]=read();
		q[a[i]]++;
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		l[a[i]]=i;
	}
	ll ans=0;
	a[0]=-2e18;
	for(map<ll,int>::iterator i=q.begin();i!=q.end();i++){
		ll t=0,j,k;
		for(j=l[i->first]-1,k=1;j>=0;j--,k++){
			t+=a[j];
			if(k*i->first-t>m){
				//cout<<ans<<' '<<i->second+k-1<<' '<<i->first<<endl;
				ans=max(ans,i->second+k-1);
				break;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
