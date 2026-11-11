#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
struct subline{
	int k;
	int a[n+1];
	int t[n+1];
}b[501];
struct goplan{
	int x,y;
}r[100001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int w[m+1];
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i].k;
		for(int j=1;j<=b[i].k;j++){
			cin>>b[i].a[j]>>b[i].t[j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>r[i].x>>r[i].y;
	}
	return 0;
}	
