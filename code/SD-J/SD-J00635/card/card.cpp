#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//vector pop从对队尾出 
const int N=1e6;
ll n,m,a[N],tong[N];
int main(){
	freopen("card.in","r",stdin); 
	freopen("card.out","w",stdout); 
	/*a.push_back(1);
	for(ll i=0;i<a.size();i++){
		cout<<a[i];
	}
	a.push_back(2);
	for(ll i=0;i<a.size();i++){
		cout<<a[i];
	}
	a.push_back(3);
	for(ll i=0;i<a.size();i++){
		cout<<a[i];
	}
	a.push_back(4);
	for(ll i=0;i<a.size();i++){
		cout<<a[i];
	}
	cout<<endl;
	a.pop_back();
	for(ll i=0;i<a.size();i++){
		cout<<a[i];
	}
	a.pop_back();
	for(ll i=0;i<a.size();i++){
		cout<<a[i];
	}
	a.pop_back();
	for(ll i=0;i<a.size();i++){
		cout<<a[i];
	}
	a.pop_back();
	for(ll i=0;i<a.size();i++){
		cout<<a[i];
	}*/
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(ll i=1;i<=n;i++){
		bool vis[N]={}; 
		vector<int> s;
		for(ll j=i;j<=n;j++){
			ll flag=0;
			for(ll k=0;k<s.size();k++){
				if(s[k]==a[j]){
					flag=1;
				}
			}
			if(flag){
				for(ll k=0;k<s.size();k++){
					if(s[k]==a[j]){
						flag=k;
					}
				}
				for(ll k=flag-1;k<s.size();k++){
					s.pop_back();
				}
			}	
			s.push_back(a[j]);
		}
		for(ll j=0;j<s.size();j++){
			if(!vis[i]){
				tong[s[j]]++;
				vis[i]=1;
			}
			cout<<s[j];
		}
	}
	for(ll i=1;i<=m;i++){
		cout<<tong[i]<<" ";
	}
	return 0;
} 
