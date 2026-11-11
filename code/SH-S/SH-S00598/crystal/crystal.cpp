#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m,mx=0;
	cin>>n>>m;
	vector<ll> crys(n);
	for(int i=0;i<n;i++){
		cin>>crys[i];
	}
	sort(crys.begin(),crys.end());
	for(ll i=0;i<n;i++){
		ll lt=m,cnt=1;
		ll j=i;
		while(j>0){
			j--;
			if(lt>=crys[i]-crys[j]) lt-=(crys[i]-crys[j]);
			else break;
			cnt++;
		}
		//cout<<cnt<<" ";
		mx=max(cnt,mx);
	}
	cout<<mx;
	return 0;
} 
