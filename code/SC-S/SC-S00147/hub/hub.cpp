#include<bits/stdc++.h>
using namespace std;
long long n,k,x[2000005],c,t,d,u[1000005],v[1000005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	long long op=t-1;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u[i]>>v[i];
		}
		cout<<op<<'\n';
		op++;
	}
	
	
	return 0;
}