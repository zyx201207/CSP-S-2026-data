#include<bits/stdc++.h>
using namespace std;
int w[10002];
int t[10002][10002];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,r;
	cin>>c,n,m,d,q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<d;j++){
			cin>>t[i][j];
		}
	}
	int x1,x2,y1,y2;
	cin>>x1>>x2>>y1>>y2;
	cout<<w[x1]+t[x1][x1]+t[x1][y1]+t[y1][y1]+t[y1][y2]+t[y2][y2]+t[y2][x2]+w[x2];
	cout<<endl;
	cout<<w[y1]+t[y1][y1]+t[y1][y2]+w[y2];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
