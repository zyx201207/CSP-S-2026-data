#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pii pair<ll,char>
#define xx first
#define yy second
const int N=2e5+10;
ll s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	deque<pii> q;
	ll ans=0;
	for(int i=1;i<=n;++i){
		int a;
		char b;
		cin>>a>>b;
		q.push_back({a,b});
	} 
	for(ll i=0;i<=n&&q.size()>1;++i){
		ll x1=q.front().xx;
		char y1=q.front().yy;
		q.pop_front();
		ll x2=q.back().xx;
		char y2=q.back().yy;
		q.pop_back();
		if(y1==y2){
			if(x1>x2) q.push_front({x1-x2,y1});
			if(x1<x2) q.push_back({x2-x1,y2});
		}
		else{
			if(x1>x2){
				ans+=x2;
				q.push_front({x1-x2,y1});
			}
			if(x1<x2){
				ans+=x1;
				q.push_back({x2-x1,y2});
			}
			if(x1==x2){
				ans+=x1;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
