#include<bits/stdc++.h>
using namespace std;
int n,m,f[300004];
int a[500005],c[300005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		f[a[i]]++;
		f[a[i]]%=2;
	}
	for(int i=0;i<=n;i++){
		for(int j=1;j<=m;j++){
			c[j]+=f[j];
		}
		f[a[i]]=(f[a[i]]+1)%2;
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}