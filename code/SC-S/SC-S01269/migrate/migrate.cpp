#include<bits/stdc++.h>
int x[2000005];
using namespace std;
int main(int argc,const char *argv[]){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
		int seed=1;
		if(argc>1) seed=atoi(argv[1]);
		srand(time(0)*2/3%198+seed*17);
		int c,t;
		cin>>c>>t;
		while(t--){
			int n,d;
			cin>>n;
			for(int i=1;i<=n;i++) scanf("%d",&x[i]);
			int onehundredpoint;
			while (10)
				onehundredpoint=rand()%(n/2+1);
			cout<<onehundredpoint<<endl;
		}
	return 0;
}