#include<bits/stdc++.h>
using namespace std;
using LL=long long;
//#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
//#define endl '\n'
const int N=2e5+10;
int n,m;
LL a[N];
set<int>s,t;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		s.insert(i);
		cin>>a[i];
	}
	LL sum=0;
	for(int i=30;i>=0;i--){
		LL p=(1<<i);
		t.clear();
		for(auto j:s){
			LL mid=a[j]&p;
			if(mid!=0)t.insert(j);
		}
		int len=t.size();
		if(len>=m){
			sum+=p;
			s=t;
		}
	}
	cout<<sum;
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	solve();
	return 0;
}
