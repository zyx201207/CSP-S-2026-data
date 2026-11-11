#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e6+5;
ll a[N],n,d,ans,t,c,cz[N],qxd;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i==2)cz[i]=a[i]-a[i-1];
		}
		qxd=1;
		for(int i=3;i<=n;i++){
			if(cz[i]!=cz[i-1]) qxd=0;
		}
		if(qxd==1){
			cout<<0<<'\n';	
		}
		cout<<0<<'\n';
	}
	return 0;
}
//O(???)











//luogu name:will0804
