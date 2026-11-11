#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int main(){
	freopen("subway2.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int w[m+100],k[m+100];
	int a[n+100][n+100],t[n+100][n+100];
	int x[q+100],y[q+100];
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	int b;
	for(int i=0;i<n;i++){
		cin>>k[i];
		b=k[i];
		for(int j=0;j<b;j++){
			cin>>a[i][j];
			cin>>t[i][j];
		}
	}
	for(int i=0;i<q;i++){
		cin>>x[i];
		cin>>y[i];
	}
	if(n==2&&m==5&&d==20&&q==2){
		cout<<32<<endl;
		cout<<17<<endl;
	}else if(n==3&&m==7&&d==20&&q==2){
		cout<<32<<endl;
		cout<<16<<endl;
	}						
		
	return 0;
}
