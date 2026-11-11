#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=2e6+5;
int c,t,n,k,u,v;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=0,u,v;i<n-1;i++)cin>>u>>v;
		int ans=0;
		for(int i=1;i<n;i<<=1)ans++;
		cout<<ans-k<<endl;
	}//rp++ 
	return 0;
}
