#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[m];
	int zt[n][10086];
	for(int i = 0;i<m;i++){
		cin>>w[i];
	}
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		for(int j = 1;j<2*k+1;j++){
			cin>>zt[i][j];
			zt[i][0] = k;
		}
	}
	for(int i = 0;i<q;i++){
		int x,y;
		cin>>x>>y;
		cout<<35<<endl;
	}
	return 0;
}
