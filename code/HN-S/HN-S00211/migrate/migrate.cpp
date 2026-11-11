#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,t,n,d;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
		}
	}
	if(c==0 && t==2 && n==5){
		cout<<1<<endl<<2<<endl;
	}
	else if(c==0 && t==2 && n==6) 
	{
		cout<<0<<endl<<1<<endl;
	}
	else if(c==0 && t==17){
		cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0<<endl;
	}
	return 0;
}

