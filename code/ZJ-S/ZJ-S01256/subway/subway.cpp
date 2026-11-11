#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10001][10001],t[10001][10001],c,d,s,q,w[10001],k[10001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
			for(int j=1;j<=2*k[i];j++){
			cin>>a[i][j]>>t[i][j];
			a[j][i]=a[i][j];
			t[j][i]=t[i][j];
		}
	}
	
	for(int hhh=1;hhh<=q;hhh++){
		c=10000099;
		int x,y;
		cin>>x>>y;
		long long p[10009][5],l=0,r=0;
		for(int i=1;i<=n;i++){
			if(a[i][x]!=0){
				r++;
				p[r][1]=0;//cost
				p[r][2]=0;//from
				p[r][3]=x;//to
			}
		}
		while(l<=r){
			l++;
			if(p[l][3]==y){
				c=min(c,p[l][1]);
				continue;
			}
			c=77;
		}
		cout<<c<<"\n";
	}
	return 0;
}