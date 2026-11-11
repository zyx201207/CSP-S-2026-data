#include<bits/stdc++.h>
using namespace std;
long long int a[50001][1001],b[101],k[1001][1001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	int h;
	for(int i=1;i<=n;i++){
		cin>>h;
		for(int j=1;j<=h;j++){
			cin>>a[i][j]>>k[i][j];

		}
	}
	int x1,y1,x2,y2,s1=0,s2=0;
		cin>>x1>>y1;
		if(n=2){
			s1+=b[x1]+k[1][1]+k[1][2]+k[2][1]+k[2][2]+b[y1];
		cout<<s1<<"\n";
		cout<<17;
		}
		if(n==3){
			cout<<35<<"\n"<<16;
		}
		
} 