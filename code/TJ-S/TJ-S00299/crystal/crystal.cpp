#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll n,m,ans;
ll a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for(ll i = 1;i<=n;i++){
		ll p = i,an = 0,s = m;
		while(s>0&&p>0){
			if(s-(a[i]-a[p])>=0){
				s-=(a[i]-a[p]);
				an++;
			}
			else{
				break;
			}
			p--;
			
		}
		ans = max(an,ans);
	}
	cout << ans;
	return 0;
} 
