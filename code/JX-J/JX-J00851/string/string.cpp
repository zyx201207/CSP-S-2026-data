#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nd{
	int x;char y;
};
list<nd> st;
int n,as;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		int a;char b;cin>>a>>b;
		st.push_back({a,b});
	}
	while(st.size()>1){
		nd c=st.front(),d=st.back();
		st.pop_front();st.pop_back();
		if(c.y!=d.y){
			as+=min(c.x,d.x);
			if(c.x>d.x) st.push_front({c.x-d.x,c.y});
			if(c.x<d.x) st.push_back({d.x-c.x,d.y});
		}
		else if(c.y==d.y){
			if(c.x>d.x) st.push_front({c.x-d.x,c.y});
			if(c.x<d.x) st.push_back({d.x-c.x,d.y});
		}
	}
	cout<<as;
	return 0;
}
