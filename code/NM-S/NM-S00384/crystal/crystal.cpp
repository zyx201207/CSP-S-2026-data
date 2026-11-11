#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    ll n,m,ma=0;
    cin >>n>>m;
    vector<ll> a(n,0);
    for(ll i=0;i<n;i++){
        cin >>a[i];
    }    
    
    sort(a.begin(),a.end());
    for(int i=1;i<n;i++){
    	a[i]+=abs(a[0]);
	}
	a[0]+=abs(a[0]);

    for(int r=n-1;r>=0;r--){
    	ll cnt=0,s=m;
    	for(int l=r-1;l>=-1;){
    		
			if(a[l]==a[r]){
    			cnt++;
    			l--;
    			continue;
			}
			else if(abs(a[l]-a[r])<=s){
				cnt++;
				s-=(a[r]-a[l]);
				l--;
				continue;
			}
			else{
				break;
			}
		}
		ma=max(ma,cnt);
	}
	cout <<ma+1;
    return 0;
}
