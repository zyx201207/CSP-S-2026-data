#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
vector<ll> z;//桌面 
ll v[500005];
vector<ll> a;//手牌 
vector<ll> q;//弃牌 
bool f[500005][300005];
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		ll x;
		cin>>x;
		a.push_back(x);
		//v[x]++;
	}
	reverse(a.begin(),a.end());
	for(ll k=0;k<a.size();k++){
		reverse(a.begin(),a.end());
		for(ll i=0;i<q.size();i++){
			a.push_back(q[i]);
		}
		q.clear();
		reverse(a.begin(),a.end());
		if(v[a[a.size()-1]]!=0){//是否重复 
			ll p;//去除 
			for(ll i=0;i<z.size();i++){
				if(z[i]==a[a.size()-1]){
					p=i;
				}
			}
			for(ll i=p;i<z.size();i++){
				q.push_back(z[i]);
				v[i]--;
			}
			for(ll i=p;i<z.size();i++)
				z.pop_back();
		}
		z.push_back(a[a.size()-1]);//放入第一张 
		v[a[a.size()-1]]++;
		a.pop_back();//牌离手 
		for(ll i=0;i<q.size();i++){
			f[k][q[i]]++;
		}
		
	}
	for(ll i=1;i<=m;i++){
		ll op=0;
		for(ll j=0;j<n;j++){
			if(f[j][i]==1)op++;
		}
		cout<<op<<" ";
	}
	return 0;
}
