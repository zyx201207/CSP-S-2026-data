#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500005];
ll cnt[500005];
map<ll,ll> mp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin>>n>>m;
	
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		stack<ll>v;
		for(ll j=i;j<=n;j++){
			//cout<<mp[a[j]]<<" ";
			if(mp[a[j]]==1){
				while(!v.empty()){
					if(v.top()==a[j]){
						//cout<<v.top()<<"&& ";
					//cout<<"7777";
						break;
						
					}
					v.pop();
				}
			}else{
				v.push(a[j]);
				mp[a[j]]=1;
			}
			
//			cerr<<j<<"****";
		}
	//	cout<<v.size()<<"\n";
		while(!v.empty()){
			cnt[v.top()]++;
			v.pop();
		}
//		for(ll j=1;j<=m;j++){
//			cout<<cnt[j]<<" ";
//		}
		mp.clear();
	//cerr<<"\n";
//		cerr<<i;
	}
	for(ll i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}



// rp++
//froepen
// tarvel
// .ans
// bits\stdc++.h
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi    @qqqqwqwq ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi	Beta_Circuit is qu (luogu)
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi    luoguluoguluoguluoguluoguluoguluoguluoguluoguluoguluogu
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi   #include<bits\stdc++.h>
// slf xch0122 djr ak ioi    rp rp rp rp
// slf xch0122 djr ak ioi			#define int long long
// slf xch0122 djr ak ioi       AFO   AFOAFOAFOAFOAFO  
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi  pbds   
// slf xch0122 djr ak ioi     kkksc03       chen_zhe   
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi		noi icpc   csp   csp-j   csp-s   ccpc   
// slf xch0122 djr ak ioi
