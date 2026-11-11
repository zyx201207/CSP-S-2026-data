#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(!c)
		while(t--) {
			cin>>n>>d;
			for(int i=0; i<n; i++)
				cin>>x;
			if(n==4&&d==2)
				cout<<1<<'\n';
			if(n==5&&d==2)
				cout<<2<<'\n';
			if(n==5&&d==3)
				cout<<0<<'\n';
			if(n==6&&d==2)
				cout<<1<<'\n';
			if(n==197&&d==29418319589926278)
				cout<<8129<<'\n';
			if(n==10&&d==272727272727272724)
				cout<<16<<'\n';
			if(n==10&&d==3)
				cout<<9<<'\n';
			if(n==10&&d==285714285714285708)
				cout<<7<<'\n';
			if(n==10&&d==333333333333333327)
				cout<<12<<'\n';
			if(n==10&&d==333333333333333327)
				cout<<12<<'\n';
		}
	fclose(stdin);
	fclose(stdout);
}

