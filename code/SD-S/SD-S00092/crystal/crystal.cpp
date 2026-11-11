#include<bits/stdc++.h> 
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
typedef long long ll;
const int N = 1e6+9;
ll n,m,cnt,s,be=1;
ll ans = 1;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	rep(i,1,n){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	cnt=1;
	rep(i,2,n){
		s=s+((a[i]-a[i-1])*(i-be));
		cnt++;
		while(s>m){
			s = s-(a[i]-a[be]);be++;cnt--;
		}
		ans= max(ans,cnt);
	}
	cout<<ans<<endl;
	return 0;
}
//5 5
//1 2 4 8 9
//5 8
//-3 -1 2 2 7
//315275
