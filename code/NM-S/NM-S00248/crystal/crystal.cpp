#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n,m;
	cin>>n>>m;
	vector<ll> crys(n+1);
	for(int i=1;i<=n;++i){
		cin>>crys[i];
	}
	sort(crys.begin()+1,crys.end());
	queue<ll> q;
	ll opc=0,ans=0;
	for(int i=1;i<=n;++i){
		q.push(crys[i]);
		opc+=(crys[i]-crys[i-1])*(q.size()-1);
		while(opc>m){
			opc-=(crys[i]-q.front());
			q.pop();
		}
		//cout<<opc<<"\n";
		if(q.size()>ans)ans=q.size();
	}
	cout<<ans;
	return 0;
} 
//miku miku!
