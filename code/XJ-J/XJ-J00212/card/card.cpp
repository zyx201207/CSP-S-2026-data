#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	
	vector<ll> a(n);
	stack<ll> s;
	
	vector<ll> ans(m+1,0);
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	for(ll i=0;i<n;i++){
		vector<bool> f(n,0);
		for(ll j=i;j<n;j++){
			s.push(a[j]);
//			cout<<">"<<a[j];
			if(f[a[j]]==1){
				s.pop();
				while(s.top()!=a[j]){
					f[s.top()]=0; 
					s.pop();
//					cout<<'?';
				}
			}else{
				f[a[j]]=1;
			}	
		} 
		while(!s.empty()){
//			cout<<s.top()<<' ';
			ans[s.top()]++;
			s.pop();
		}
//		cout<<endl;
	} 
	for(ll i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
} 
