#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,u,v;
int main(){
	//freopen()
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(long long i=1;i<n;i++){
			cin>>u>>v; 
		}
		cout<<ceil((n-k)*1.0/k-0.0001)<<endl;
	}
	//fclose()
	fclose(stdin);
	fclose(stdout);
	return 0;
	//Desultory Signal
}

