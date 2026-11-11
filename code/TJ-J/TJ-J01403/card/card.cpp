#include<iostream>
#include<stack>
using namespace std;
typedef long long ll;
stack <ll> a;
ll b[500005];
ll ans[500005];
bool p[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m,te;
	ll x=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++){
		int zs=n;
		x=i;
		while(zs--){
			if(x>n) continue;
			a.push(b[x]);
			if(p[b[x]]==false) p[b[x]]==true;
			else {
				if(a.size()) a.pop();
				while(a.top()!=b[x]&&a.size()){
					p[a.top()]=false;
					a.pop();
				}
			}
			x++;
		}
		while(a.size()){
			ans[a.top()]++;
			a.pop();
		}
		for(int i=1;i<=m;i++) p[i]=false;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
