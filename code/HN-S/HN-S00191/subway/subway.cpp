#include<bits/stdc++.h>
using namespace std;
const int A=5e5+5,B=5e1+5;
int c,n,m,d,q,w[A],k[505]
struct a[A]{
	int a,t;
}; //来这里考真是难为我了 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	} 
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j].a>>a[j].v;
		}
	}
	return 0;
}
