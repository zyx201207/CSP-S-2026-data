#include<bits/stdc++.h>
using namespace std;
int n=0;
typedef unsigned long long ull;
ull m=0;
typedef long long ll;
vector<ll> a;
vector<ll> chafen;
ull best=0;
bool cmpr(ll x,ll y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	a.resize(n+1,0);
	chafen.resize(n+1,0);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end()-1,cmpr);
	bool dengcha=true;
	chafen[0]=a[1]-a[0];
	for(int i=1;i<n-1;i++){
		chafen[i]=a[i+1]-a[i];
		if(chafen[i]!=chafen[i-1]){
			dengcha=false;
		}
	}
	if(dengcha){
		ll delta=ceil(sqrt((double)(1+8*m/chafen[0])));
		cout<<(delta-1)/2<<'\n';
		return 0;
	}
	for(int i=n-1;i>=0;i--){ 
		ull ad=0;
		ull ad_=0;
		ull curren=0;
		for(int j=i;j>0;j--){
			ad_+=chafen[j-1];
			ad+=ad_;
			if(ad<=m){
				curren+=1;
			}else{
				break;
			}
			if(curren>best){
				best=curren;
			}
		}
	}
	cout<<best+1<<'\n';
	return 0;
}
