#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int maxn=3e5+5;
ll n,m;
ll a[maxn];
ll lg[maxn];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		stack<ll>s;
		for(ll j=i;j<=n;j++){
			stack<ll>t;
			bool flag=false;
			while(!s.empty()){
				if(s.top()==a[j]){
					flag=true;
				}
				t.push(s.top());
				s.pop();
			}
			s=t;
			if(flag){
				while(s.top()!=a[j]){
					s.pop();
				}
			}
			else{
				s.push(a[j]);
			}
		}
		while(!s.empty()){
			lg[s.top()]++;
			s.pop();
		}
	}
	for(ll i=1;i<=m;i++){
		cout<<lg[i]<<" ";
	}
	return 0;
}
