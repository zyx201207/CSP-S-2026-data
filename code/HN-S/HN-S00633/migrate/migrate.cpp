#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e6+5;
ll c,t,n,d,x[N],cnt,sum[3];
ll l(ll u,ll v){
	sum[0]++;
	if(u==v){
		if(sum[0]==sum[1]){
			sum[2]++;
		}
		sum[0]--;
		return sum[0];
	}
	for(int i=u+1;i<=v;i++){
		if(x[i]<=d){
			if(sum[1]<l(i,v)){
				sum[2]=0;
				sum[1]=l(i,v);
			}
		}else{
			break;
		}
	}
	sum[0]--;
	return sum[1];
}
bool two(ll u,ll v){
	sum[0]=0;
	sum[1]=0;
	sum[2]=0;
	int f=l(u,v);
	return sum[2]>=2;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cnt=0;
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>x[i];
		}
		for(ll i=1;i<=n;i++){
			for(ll j=i;j<=n;j++){
				if(two(i,j)){
					cnt++;
				}
			}
		}
		cout<<cnt;
	}
	return 0;
}
