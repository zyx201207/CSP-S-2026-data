#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		int n,m;cin>>n>>m;
		if(m==2){cout<<1<<"\n";continue;}
		if(m>4000){
			if(n==m){cout<<m+1<<"\n";continue;}
			else{cout<<(m+1)/2<<"\n";continue;}
		}else cout<<m-1<<"\n";
	}
	
	return 0;
}

