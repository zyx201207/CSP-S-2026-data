#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,a[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);	
	cin >> n >> m;
	for(int i=0; i<n; i++) cin >> a[i];
	ll cha=a[1]-a[0];
	m/=cha;
	ll p=1,i=0;
	bool b=1;
	while(i<=n&&b==0){
		int t=2;
		while(t){
			if(m>=0){
				m-=p*cha;
				ans++;
			}
			else{
				b=0;
				break;
			}
		}
		p++;
		i++;
	}
	if(m<0) ans--;
	cout << ans+1;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
