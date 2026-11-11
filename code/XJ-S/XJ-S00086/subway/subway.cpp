#include<bits/stdc++.h>
using namespace std;
//const int N=10e5+10; 
long long c,n,m,d,q,T,k;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
int w[505],a[505][300],time[505][300];
	cin>>c>>n>>m>>d>>q;

	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[k][j]>>time[k][j];
		}
	}
	int x,y;
	while(!q){
		q--;
		cin>>x>>y;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				T+=w[j];
				T+=time[i][j];
				if(a[i][j]==y){
					cout<<T<<endl;
				}
			}
		}
	}
	return 0;
}
