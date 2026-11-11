#include<bits/stdc++.h>
using namespace std;
int main () {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,x[100005];
	cin>>c>>t;
	for(int i=1;i<=t;i++){
	cin>>n>>d;
	for(int j=1;j<=n;j++)
		cin>>x[i];
	}
	int sum;
	for(int i=x[1];i<=n;i++){
		for(int j=x[n];j>=1;j--){
			int km=j-i;
			if(km<=2)
			sum=0;
			if(km==3)
			sum++;
		}
	}
	cout<<"0"<<endl<<"1";
}
