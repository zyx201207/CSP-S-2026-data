#include<bits/stdc++.h>
using namespace std;
using ll=long long;


int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		int N,K;
		cin>>N>>K;
		cout<<N/K+K<<'\n';
	}
	return 0;
}
