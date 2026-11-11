#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ans=1,t;
vector<ll> a,df(0); 
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		cin>>t;
		a.push_back(t);
	}
	sort(a.begin(),a.end());
	
	//for(ll i=0;i<a.size();i++) cout<<a[i]<<" ";
	
	for(ll i=1;i<n;i++){
		df.push_back(a[i]-a[i-1]);
	}	
	sort(df.begin(),df.end());
	
	//for(ll i=0;i<df.size();i++) cout<<df[i]<<" ";
	
	ll i=0;
	while(m>=0){
		
		m-=(df[i]);
		df[i+1]+=df[i];
		
		//printf("m=%d df.i=%d i=%d\n",m,df[i+1],i);
		if(m<0) i--;
		else {
			i++;
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
