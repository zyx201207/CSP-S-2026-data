#include<bits/stdc++.h>
#define ll long long
using namespace std;
long long n,m,a[510000];
set<int>s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ll x=a[i];
		if(!s.count(x))
		s.insert(x);
		else{
			cout<<x;return 0;
		}
	}
	return 0;
}

