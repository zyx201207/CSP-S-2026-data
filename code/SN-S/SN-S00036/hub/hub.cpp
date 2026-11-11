#include<bits/stdc++.h>
using namespace std;

int c,t;
int n,k;

int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	
	cin>>c>>t;
	while(t--) {
		cin>>n>>k;
		for(int i = 1;i<=n-1;i++) {
			int gunf,gunm;
			cin>>gunf>>gunm;
		}
		cout<<pow(ceil(sqrt((sqrt(n) + k)/2)/2),2)<<'\n';
	}
	
	return 0;
} 
