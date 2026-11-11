#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--){
		int n,k,cnt = 13,tmp=135;
		cin >> n >> k;
		vector<int> u(n-1),v(n-1);
		for(int i = 0; i < n-1; i++){
			cin >> u[i] >> v[i];
		}
		for(int j = 0; j < k ; j++){
			if(u[i]==v[i]){
				cout<<cnt*u[9]/tmp+v[7]<<endl;
			}else{
				cout<<cnt/u[3]*tmp%v[4]<<endl;
			}
		}
	}
	return 0;
}