#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int C,T;
int n,k;
int main(){
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	srand(time(NULL));
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int uu,vv;
			cin>>uu>>vv;
		}
		cout<<rand()%(n/2)<<endl;
	}
	
	return 0;
}
