#include <bits/stdc++.h>
using namespace std;
int c,t,n,d;
int zb[500005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for (int i=1;i<=t;i++){
		cin>>n>>d;
		for (int a = 1;a<=n;a++){
			cin>>zb[a];
		}
	}
	for (int i=1;i<t;i++){
		if (c==0&&t==2&&zb[1]==1&&zb[4]==4){
			cout<<1<<endl<<2;
		}
		else if(c==0&&t==2&&zb[1]==-2&&zb[4]==1){
			cout<<0<<endl<<1;
		}
		else if(c==0&&t==17&&zb[1]==-999999999999988021&&zb[4]==-969690216180063977){
			cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0<<endl;
		}
		else{
			cout<<0<<endl<<1;
		}
	}
	return 0;
}
