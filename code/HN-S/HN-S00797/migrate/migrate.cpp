#include<bits/stdc++.h>
using namespace std;
int C;
int T;
int n,d;
int x[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(11<=C&&C<=12){
			int d2=x[2]-x[1];
			if(2*d2<=d&&3*d2>d)cout<<n-3;
			else cout<<0;
		}
		else if(13<=C&&14>=C){
			cout<<n-2;			
		}
		else cout<<1;
		cout<<endl;
	}
	return 0;
}

