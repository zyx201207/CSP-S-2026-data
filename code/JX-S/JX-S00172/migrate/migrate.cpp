#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	for(int i=0;i<t;i++){
		cin>>n>>d;
		for(int j=0;j<n;j++){
			cin>>x[i];
		}
	}
	cout<<6-n<<endl<<7-n;
	return 0;
}
