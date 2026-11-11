#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+50,M=3e5+50;
int n,m,a[N],b[M],d[M],c[M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
		d[a[i]]=i;
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) b[j]=0;
		for(int j=i;j<=n;j++){
			j=d[a[j]];
			b[a[j]]=1;
		}
		for(int j=1;j<=m;j++) c[j]+=b[j];
	}
	for(int i=1;i<=m;i++) cout<<c[i]<<' ';
	return 0;
}
