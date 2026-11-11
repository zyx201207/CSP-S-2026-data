#include <bits/stdc++.h>
using namespace std;
int a[2005],b[7][2005];
long long c[25][25];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if (m==n){
		long long a,b;
		cin>>a;
		for (int i=2;i<=n;i++){
			cin>>b;
			a&=b;
		}
		cout<<a;
	}
	if (n>20){
		
		for (int i=1;i<=n;i++){
			cin>>a[i];
		}
		for (int i=1;i<=n;i++){
			b[0][i- 1]=a[i];
		}
		for (int i=1;i<=m;i++){
			for (int j=i;j<=n;j++){
				b[i][j]=max(b[i][j- 1],b[i- 1][j- 1]&a[j]);
			}
		}
		cout<<b[m][n];
	}
	else {
		for (int i=1;i<=n;i++){
			cin>>a[i];
		}
		for (int i=1;i<=n;i++){
			c[0][i-1]=a[i];
		}
		for (int i=1;i<=m;i++){
			for (int j=i;j<=n;j++){
				c[i][j]=max(c[i][j- 1],c[i- 1][j- 1]&a[j]);
			}
		}
		cout<<c[m][n];
	}
	return 0;
}
