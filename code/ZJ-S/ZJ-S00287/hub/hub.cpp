#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		pair<int,int> a;
		for(int i=1;i<n;i++){
			cin>>a.first>>a.second;
		}
		if(k==1) cout<<0<<"\n";
		else if(k==2) cout<<1<<"\n";
		else{
			if(k%2==0) cout<<(k/2+1)<<"\n";
			else cout<<(k+1)/2<<"\n";
		}
	}
	return 0;
}
