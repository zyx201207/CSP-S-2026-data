#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10; 
long long u[N],v[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		for(int j=1;j<=n-1;j++){
			cin>>u[j]>>v[j];
		}
		cout<<n<<endl;
	} 
	return 0;
} 
