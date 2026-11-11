#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,s;char c;deque<pair<ll,char>>a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;while(n--)cin>>k>>c,a.push_back({k,c});
	while(a.size()){
		if(a.size()==1)break;
		if(a.front().second!=a.back().second)s+=min(a.front().first,a.back().first);
		if(a.front().first>a.back().first)a.front().first-=a.back().first,a.pop_back();
		else if(a.front().first<a.back().first)a.back().first-=a.front().first,a.pop_front();
		else a.pop_back(),a.pop_front();
	}
	cout<<s;
	return 0;
}
