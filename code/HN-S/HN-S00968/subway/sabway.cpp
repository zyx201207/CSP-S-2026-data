#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,m,d,q,t,n,x,y,a[2000010],k[2000010],b[2000010];
signed main(){
	freopen("sabway.in","r",stdin);
	freopen("sabway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
		
	} 
	for(int j=1;j<=n;j++){
		cin>>k[j];
		for(int i=1;i<=2*k[j];i++){
			cin>>b[i];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y; 
	} 
	int cnt=0;
	for(int i=1;i<=t;i++){
		srand(time(0));
		int cnt=rand();
		cout<<cnt<<endl;
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
