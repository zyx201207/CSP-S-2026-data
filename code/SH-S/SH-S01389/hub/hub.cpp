#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,u[114514],v[114514];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int i=1;i<n;i++)
		cin>>u[i]>>v[i];
		if((n-2*d)%8==0)
		cout<<(n-2*d)/8+1<<endl;
		else
		cout<<(n-2*d)/8+2<<endl;
	}
	return 0;
} 
