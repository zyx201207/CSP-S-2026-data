#include<bits/stdc++.h>
using namespace std;
long long x[200010],y[200010];
int n,m;
long long a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		x[i]=a[i];
	}
	for(int i=2;i<=m;i++){
		for(int j=i;j<=n;j++){
			for(int q=i-1;q<=n;q++){
				y[j]=max(y[j],a[j]&x[q]);
			}
		}
		for(int j=i;j<=n;j++){
			x[j]=y[j];
		}
	}
	cout<<y[n];
	return 0;
}
