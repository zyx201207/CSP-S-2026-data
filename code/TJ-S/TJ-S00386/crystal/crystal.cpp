#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	vector<ll>v(n+1);
	vector<ll>s(n+1);
	for(int i=1;i<=n;i++){
		cin>>v[i];
		
	}
	sort(v.begin()+1,v.end());
	for(int i=1;i<=n;i++){
		cin>>v[i];
		s[i]=s[i-1]+v[i];
	}
	ll l=1,r=l,ans=0;
	while(r<=n && l<=r){
		ll lenv=(r-l+1) * v[r];
		ll lv=s[r]-s[l-1];
		if(lenv-lv<=m){
			ans=max(r-l+1,ans);
			//cout<<ans<<endl;
		}
		else{
			//cout<<ans<<' ';
			while((r-l+1) * v[r] - (s[r]-s[l-1]) >m)l++;
		
			ans=max(ans,r-l+1); 
		}
		r++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
