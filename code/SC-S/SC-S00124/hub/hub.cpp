#include <bits/stdc++.h>
using namespace std;
int n[100000000],k[100000000],u[100000000],v[100000000];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);		
	int c,t;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n[i]>>k[i];
		for(int j=0;j<n[i];j++){
			cin>>u[j]>>v[j];
		}
	}
	for(int i=0;i<t;i++){
		for(int j=0;j<n[i];j++){
			cout <<min(u[j]*k[i]/v[j],u[j]*v[j]%k[i],k[i]&v[j]/u[j]);
		}
	}
	return 0;
}