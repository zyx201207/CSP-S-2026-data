#include<bits/stdc++.h>
using namespace std;
int n,c,t,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		if(k==n)cout<<(n-1)/2+1<<endl;
		else if(k==n-1)cout<<(n-1)/2<<endl;
		else if(k==0||k==1||k==2)cout<<0<<endl;
		else if(k==3||k==4)cout<<1<<endl;
		else if(k==5)cout<<2<<endl;
		else cout<<k/2+k%2-1<<endl;
	}
	return 0;
}

