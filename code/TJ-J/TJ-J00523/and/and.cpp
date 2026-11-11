#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+1;
ll n,m,a[N],ans,c;
bool cmp(ll a,ll b){
	return a>b;
}
stack<ll> s;
int main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(ll i=2;i<=n;i++){
		if(c==m)
			if(ans&s.top()<=ans&a[i]){
				s.pop(),s.push(a[i]);
		}else{
			ans&=s.top();
			s.push(a[i]),c++;
		}
	}
	ans&=s.top();
	printf("%lld",ans);
	return 0;
}

