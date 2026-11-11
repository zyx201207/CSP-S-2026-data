#include<bits/stdc++.h>
using namespace std;

unsigned long long p(int x){
	unsigned long long k=1;
	for(int i=1;i<=x;i++) k*=2;
	return k;
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	unsigned long long c,t;
	cin>>c>>t;
	if(c>4) c=4;
	srand(time(0));
	while(t--){
		cout<<rand()*p(c)%p(p(c+1))<<"\n";	
	}
	
	return 0;
}
