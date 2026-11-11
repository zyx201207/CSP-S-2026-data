#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pli pair<long long,int>
using namespace std;
deque<pli> q;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		ll a;
		char tmp;
		cin>>a>>tmp;
		int b=tmp;
		q.push_back(mp(a,b));
	}
	ll ans=0;
	while(q.size()>1){
		pli x=q.front();
		q.pop_front();
		pli y=q.back();
		q.pop_back();
		if(x.first==y.first){
			if(x.second!=y.second) ans+=x.first;
		}else if(x.first>y.first){
			if(x.second!=y.second) ans+=y.first;
			x.first-=y.first;
			q.push_front(x);
		}else{
			if(x.second!=y.second) ans+=x.first;
			y.first-=x.first;
			q.push_back(y);
		}
	}
	cout<<ans;
	return 0;
}
