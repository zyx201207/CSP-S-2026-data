#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+7;
priority_queue<ll,vector<ll>,greater<ll> > que;
ll n,m,cnt=1,sum=0;
ll en[N],cha[N];
bool cmp(ll x,ll y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>en[i];
	}
	sort(en+1,en+n+1,cmp);
	for(int i=1;i<=n-1;i++){
		cha[i]=en[i+1]-en[i];
	}
	for(int i=1;i<=n;i++){
		sum+=i*cha[i];
		cnt++;
		//cout<<sum<<" ";
		if(sum==m) break;
		if(sum>m){
			cnt--;
			break;
		} 
		if(sum<m){
			if(cnt==n) break;
		}else continue;
	}
	cout<<cnt;
	return 0;
}
