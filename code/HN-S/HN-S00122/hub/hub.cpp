#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e6+7;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		if(n%2==1){
			int m=n/2;
			if(k==1) cout<<m/2+1<<"\n";
			else{
				m-=k;
				cout<<m/3+1<<"\n";
			}
		}
	}
	return 0; 
}
