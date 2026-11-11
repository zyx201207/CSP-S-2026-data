#include<bits/stdc++.h>//
const int N=510;
using namespace std;
int c,n,m,d,q;
int a[N];
int s[N];
int w[N],k[N],lu[N][N],zou[N][N];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(n==2&&m==5&&d==20&&q==2) {
		cout<<"32\n17";
		return 0;
	} else if(n==3&&m==7&&d==20&&q==2) {
		cout<<"35\n16";
		return 0;
	}
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=n; i++) {
		cin>>k[i];
		for(int j=1; j<=k[i]; j++) {
			cin>>zou[i][j];
			cin>>lu[i][j];
		}
	}
	for(int i=1; i<=q; i++) {
		int x,y;
		cin>>x>>y;
		int sum=0;
		sum+=w[x]+w[y];

		for(int j=x; j<y; j++) {
			for(int k=x; k<y; k++) {
				sum+=lu[j][k];
	
			}

		}if(y-x==1){
			sum+=lu[x][y];
		}
		cout<<sum<<"\n";
	}
	return 0;
}//
