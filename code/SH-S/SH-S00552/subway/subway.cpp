#include<bits/stdc++.h>
using namespace std;
int main(){
		freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	static mt19937 rng(
		static_cast<unsigned>(chrono::steady_clock::now().time_since_epoch().count())
	);
	int ans=uniform_int_distribution<int>(1,1000000000)(rng);
	cout<<ans;
} 
