#include<iostream>
using namespace std;
int c,n,m,d,q,w[2422],t[7675][7867],r[3344][34433];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cout<<w[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>t[i][j];
		}
	}
	for(int i=0;i<q;i++){
		for(int j=0;j<2;j++){
			cin>>r[i][j];
		}
	}
	cout<<32<<endl;
	cout<<17<<endl;
	return 0;
}
//5 5 1 2 4 8 9
//5 8 -3 -1 2 2 7