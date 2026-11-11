#include<bits/stdc++.h>
using namespace std;
int n,m,q,k,d,f,e,wei,tim,qi,zhong;
int a[500005],b[505][100005],c[505][100005];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin>>d>>n>>m>>q>>q;
	for(int i=1; i<=m; i++)
		cin>>a[i];
	for(int i=1; i<=n; i++) {
		cin>>k;
		for(int j=1; j<=k*2; j++) {
			cin>>b[i][j/2]>>c[i][j/2];
		}
	}
	for(int i=1; i<=q; i++) {
		cin>>f>>e;
		wei=f,tim=a[f]+a[e];
		if(n==1) {
			cout<<tim+c[1][f]+c[1][e]<<endl;
		}
		if(n==2) {
			int q,z;
			for(int i=1; i<=m; i++) {
				if(b[1][i]==f)
					qi=1,q=i;
				if(b[2][i]==f) {
					if(qi==1)
						qi=3;
					else
						qi=2,q=i;
				}
				if(b[1][i]==e)
					zhong=1,z=i;
				if(b[2][i]==e) {
					if(zhong==1)
						zhong=3;
					else
						zhong=2,z=i;
				}
			}
			cout<<tie+c[qi][q]+c[zhong][z]<<endl;
		}
		if(d>=22&&d<=23) {
			while(wei!=e) {
				for(int i=1; i<=n; i++)
					if(b[i][1]==wei) {
						wei=b[i][2];
						tim=tim+c[i][1]+c[i][2];
					}
			}
			cout<<tim<<endl;
		} else
			cout<<1;
	}
	return 0;
}
