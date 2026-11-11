#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
int x[2000003];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	for(int k=0;k<t;k++){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		int a=x[2]-x[1];
		bool c=1;
		for(int i=3;i<=n;i++){
			if(x[i]-x[i-1]!=a)c=0;
		}
		if(c){
			int b=d/a;
			int e=b*2-1;
			cout<<n-e<<'\n';
		}
	}
	return 0;
} 
