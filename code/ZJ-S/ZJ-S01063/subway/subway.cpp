#include<bits/stdc++.h>

using namespace std;

long long int c,n,m,d,q,w[505],k[500][501],mp[501][501];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long int i=1;i<=n;i++){
		cin>>k[i][1];
		for(long long int j=2;j<=k[i][1]*2+1;j++){
			cin>>k[i][j];
			if(j!=2&&j%2==0){
				mp[j-2][j]=1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			cout<<mp[i][j]<<' ';
		}
		cout<<endl;
	}
	for(int i=1;i<=q;i++){
		long long int x,y;
		cin>>x>>y;
		
	}
	cout<<"subway\n";
	return 0;
}
