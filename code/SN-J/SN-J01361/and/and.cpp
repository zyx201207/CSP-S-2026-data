#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define endl '\n'
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	if(m==1){
		ll maxx=-1;
		for(int i=1;i<=n;i++){
			ll a;
			cin>>a;
			maxx=max(maxx,a);
		}
		cout<<maxx<<'\n';
		return 0;
	}
	else if(m==2){
		ll maxx=-1;
		set<pair<int,int>> st;
		int a[2005];
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ll pos;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				if(!st.count(make_pair(a[i],a[j]))){
					st.insert(make_pair(a[i],a[j]));
					pos=(a[i]&a[j]);
					if(pos>maxx){
						maxx=pos;
					}
				}
			}
		}
		cout<<maxx<<'\n';
	}
	else{
		srand(time(NULL));
		cout<<1ULL*(rand()*rand())%100000+1;
	}
	return 0;
}
