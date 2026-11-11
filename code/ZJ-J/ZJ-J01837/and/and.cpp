#include<bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define ft first
#define sd second
using namespace std;
int val[200010];
int n,m;
vector<int> noww,nowww;
int ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>val[i];
		noww.pb(val[i]);
	}
	for(int i=30;i>=0;i--){
		for(auto shu:noww){
			if((shu>>i)&1){
				nowww.pb(shu);
			}
		}
		if(nowww.size()>=m){
			ans+=(1<<i);
			noww=nowww;
		}
		nowww.clear();
	}
	cout<<ans;
	return 0;
}
