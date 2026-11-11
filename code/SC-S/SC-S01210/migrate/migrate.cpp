#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int c,t,n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int i,j;
	cin>>c>>t;
	for(i=1;i<=t;i++){
		cin>>n>>d;
		for(j=1;j<=n;j++){
			cin>>a[j];
		}
		if((c==11||c==12)){
			if(n>=4&&a[1]-a[0]<=d)cout<<n-3;
			else    cout<<0;
		}
		if(c==13||c==14){
			if(n>=4)cout<<n-3;
			else    cout<<0;
		}
	}
	return 0;
}