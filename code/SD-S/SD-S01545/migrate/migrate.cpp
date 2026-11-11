#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int c,t,n,d,x[N],dis[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			dis[i]=x[i]-x[i-1];
		}
		cout<<n-d/dis[2]-1<<endl;
	}
	return 0;
} 
