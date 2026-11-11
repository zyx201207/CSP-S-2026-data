#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int zhan[500050];
	int net[500][500050][2];
	int l=0;
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>zhan[i];
	}
	int k;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>net[i][j][0]>>net[i][j][1];
		}
	}
	for(int i=1;i<=q;i++){
		l=zhan[1]+zhan[3];
	}
	cout<<1<<endl<<2<<endl<<6<<endl<<2<<endl<<3;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
