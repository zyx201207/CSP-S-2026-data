#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+5;
int a[N],b[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	stack<int> s,s1;
	map<int,int> mp;
	for(int i=n;i>=1;i--){
		s.push(a[i]);
		mp[a[i]]++;
		if(mp[a[i]]==2){
			s.pop();
			mp[a[i]]=1;
			while(s.top()!=a[i]){
				int t=s.top();
				mp[t]=0;
				s.pop();
			}
		}
		int l=s.size();
		for(int j=1;j<=l;j++){
			int t=s.top();
			b[t]++;
			s1.push(s.top());
			s.pop();
		}
		for(int j=1;j<=l;j++){
			int t=s1.top();
			s.push(t);
			s1.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
}
