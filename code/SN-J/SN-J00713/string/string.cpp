//郭昕宇 西安市铁一中学 SN-J00713 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin>>n;
	ll cnt=0;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		cnt+=a[i];
	}
	ll l=1,r=n;
	ll ans=0;
	while(l<r){
		if(a[l]>a[r]){
			a[l]-=a[r];
			if(c[l]!=c[r])ans+=a[r];
			r--;
		}
		else if(a[l]==a[r]){
			if(c[l]!=c[r])ans+=a[l];
			l++;
			r--;			
		}
		else{
			if(c[l]!=c[r])ans+=a[l];
			a[r]-=a[l];
			l++;
		}
	}
	cout<<ans;
	return 0;
}
