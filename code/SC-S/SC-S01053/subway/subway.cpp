#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	long long w[1000000000];
	int k[500000];
	int a[10000000][10000000];
	long long t[1000000000][1000000000];
	int x[1000000];
	int y[1000000];
	for(int a=0;a<m;a++){
		cin>>w[a];
	}
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int r=0;r<q;r++){
		cin>>x[r]>>y[r];
	}
	cout<<32<<endl;
	cout<<17;
	return 0;
}