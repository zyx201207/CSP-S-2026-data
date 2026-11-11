#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500030];
ll b[300070];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	map<ll,ll>s;
	stack<ll>st;
	ll n,m;
	cin>>n>>m;
	for (ll i=1;i<=n;i++)cin>>a[i];
	for (ll i=1;i<=n;i++){
		s.clear();
		//cout<<endl<<endl<<endl;
		for (ll j=i;j<=n;j++){
			if (s[a[j]]<1){
				s[a[j]]++;
				st.push(a[j]);
			}else{
				s[a[j]]=1;
				while(st.top()!=a[j]){
					s[st.top()]--;
					st.pop();
				}
			}
//			stack<ll>k1;
//			while (!st.empty()){
//				cout<<st.top()<<" ";
//				k1.push(st.top());
//				st.pop();
//			}
//			while (!k1.empty()){
//				//cout<<st.top()<<" ";
//				st.push(k1.top());
//				k1.pop();
//			}
//			cout<<endl;
		}
		while (!st.empty()){
			b[st.top()]++;
			s[st.top()]--;
			st.pop();
		}
	}
	for (ll i=1;i<=m;i++)cout<<b[i]<<" ";
	return 0;
} 
