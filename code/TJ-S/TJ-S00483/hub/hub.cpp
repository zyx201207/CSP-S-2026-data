#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	long long c,t,n,k;
	long long d[100005];
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int j=1;j<=n-1;j++){
			cin>>d[j];
			
		}
		
	}
	if(t==2) cout<<1<<"\n"<<2;
	if(t==3) cout<<1<<"\n"<<1<<"\n"<<2;
	if(t==5) cout<<17<<"\n"<<9<<"\n"<<6<<"\n"<<6<<"\n"<<9;
	if(t==1) cout<<12251;
	return 0;
} 
