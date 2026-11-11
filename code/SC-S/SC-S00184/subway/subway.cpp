#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int k[100000];
int w[150000];
int t[10000];
int a,r;
int x[100000];
int y[100000];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=2;i++){
		cin>>k[i];
		for(int j=1;j<=2k[i];j++){
			cin>>a[j]>>t[j];
		}
	}
	for(int i=1;i<=r+n+2;i++){
		for(int j=1;j<=2;j++){
			cin>>x[j]>>y[j];
			t[i]+=w[x[j]];
			t[i]+=w[y[j]];
		}
	}
	for(int i=1;i<=r;i++){
		cout<<t[i];
	}
}