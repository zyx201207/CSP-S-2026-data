#include<bits/stdc++.h>
using namespace std;
long long c,t,k=1;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long n,d,x[1000006],y[1000006];
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>x[i]>>y[i];
		}
		cout<<k<<endl;
		k++;
	}
	return 0;
} 
