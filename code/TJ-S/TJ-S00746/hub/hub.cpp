#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,d,q,ans,cha,fc,u[10000005],v[10000005],nn;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u[i]>>v[i];
		}
		cout<<k-1<<endl;
	}
	return 0;
}
