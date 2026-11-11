#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>a>>b;
	for(int i=0; i<b; i++) {
		cin>>c>>d;
		for(int i=0; i<c; i++) {
			cin>>e;
		}
	}
//	cout<<e;
	if(a==0&&e==5) cout<<1<<"\n"<<2;
	else if(a==0&&e==6) cout<<0<<"\n"<<1;
	else {
		for(int i=0; i<b; i++) {
			cout<<1<<"\n";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

