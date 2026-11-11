#include<bits/stdc++.h>
using namespace std;
int n, m, s, x, y, z, d, e, g, a[200001], b[200001][30], c[200001], f[31];
int main()
{
	freopen("and.in", "r","stdin");
	freopen("and.out ", "w", "stdout");
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		x=1;
		for(int j=1; j<=a[i]; j++){
			x=x*2;
			if(x>=a[i]){
				x=j;
				break;
			}
		}
		y=max(x, y);
		s=2;
		for(int j=1; j<=x; j++){
			if(a[i]%s>=s/2){
				b[i][j]=1;
			}
			s=s*2;
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=y; j>=1; j--){
		}
	}
	for(int i=y; i>=1; i--){
		x=0;
		for(int j=1; j<=n; j++){
			if(b[j][i]==1){
				x++;
			}
		}
		if(x>=m){
			x=i;
			s=0;
			for(int j=1; j<=n; j++){
				if(b[j][i]==1){
					s++;
					c[s]=j;
				}
			}
			break;
		}
	}
	for(int i=x; i>=1; i--){
		z=0;
		for(int j=1; j<=s; j++){
			if(b[c[j]][i]==1){
				z++;
			}
		}
		if(z>=m){
			g++;
			f[g]=i;
		}
	}
	for(int i=1; i<=g; i++){
		e=1;
		for(int j=1; j<f[i]; j++){
			e=e*2;
		}
		d=d+e;
	}
	cout<<d;
	return 0;
}