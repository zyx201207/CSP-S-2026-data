#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int c,n,m,k,q,w[N],a[N][N],t[N][N]; 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>k>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=2;i++){
    	int x;
    	cin>>x;
    	for(int j=1;j<=x;j++){
    		cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
	}
	cout<<w[1]+t[1][1]+(t[1][2]+t[2][2])+t[2][3]+w[3];
	cout<<endl;
	cout<<w[1]+t[1][1]+t[1][2]+w[2];
	return 0;
}
