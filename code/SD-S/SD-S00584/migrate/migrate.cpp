#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
vector<vector<int>> info;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	int temp,k;
	for(int i=1;i<=m;i++){
		cin>>temp;
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>temp>>temp;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>temp>>temp;
	}
	
	return 0;
}
