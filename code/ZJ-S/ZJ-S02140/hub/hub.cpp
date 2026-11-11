#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,u[2000005],v[2000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	int cn=0;
	while(t--){
		cin>>n>>k;
		cn++;
		for(int i=1;i<n;i++){
			cin>>u[i]>>v[i];
		}
		cout<<cn;
	}
	return 0;
}
