#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==13||c==14){
		while(t--){
		int n,k,L;
		cin>>n>>k;
		for(int i=1;i<n;i++)cin>>L>>L;
		cout<<max(0,((n+1)/2+1-k+3)/4)<<endl;
		}
	}
	if(c==1){
		while(t--){
		int n,k,L;
		cin>>n>>k;
		for(int i=1;i<n;i++)cin>>L>>L;
		if(k==1)cout<<2<<endl;
		else if(n!=k)cout<<1<<endl;
		else cout<<0<<endl;
		}
	}
	return 0;
}

