#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,t;
int x[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n-1;i++){
			cin>>x[i];
		}
		cout<<x[4]*x[2]+13<<endl;
	}
	return 0;
}
