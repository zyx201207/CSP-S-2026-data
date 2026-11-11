#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[1000000][10000],q[1000000],k;
int v[1000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	if(m==1){
		int u=0;
		for(int i=1;i<=n;i++){
			int h;
			cin>>h;
			if(h>=u)u=h;
		}cout<<u;return 0;
	}
	for(int i=1;i<=n;i++){
		int d,c=1;
		cin>>d;
		q[i]=d;
		while(d>0){
			a[i][c]=d%2;
			c++;
			d/=2;
		}k=max(k,c-1);
		}
	bool f=0;
	for(int i=k;i>=1;i--){
			int c=0,k=0;
			for(int j=1;j<=n;j++){
				if(a[j][i]==1){
					c++;
					v[k]=j;
					k++;
				}
				if(c==m){
					f=1;
					break;
				}
			}
			
			if(f)break;
		}
	
	int g=q[v[0]];
	for(int i=0;i<m;i++){
		g &= q[v[i]];
	}cout<<g;
	return 0;
}
