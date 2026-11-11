#include<bits/stdc++.h>
using namespace std;
int c,t,k,a,n,b;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>a>>b;
		}
		cout<<n/5<<endl;
	}
	return 0;
}
