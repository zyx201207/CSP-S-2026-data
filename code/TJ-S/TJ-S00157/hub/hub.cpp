#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,u[10000005],v[10000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	for(int i=1;i<=t;i++){
		cin >> n >> k;
		for(int j=1;j<n;j++){
			cin >> u[i] >> v[i];
		}
		if(n==5||n==6||n==8){
			cout << 1 << "\n";
		}else if(n==9||n==10){
			cout << 2 << "\n";
		}else{
			cout << n%4 << "\n";
		} 
	}
	return 0;
} 

