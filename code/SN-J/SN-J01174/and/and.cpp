#include<bits/stdc++.h>
using namespace std;
long long f[10005];
long long a[10005];
long long  maxx_and=0;
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=-114514;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j+=m-1){
		f[i]=max(f[j],a[i]&a[j+1]);
		}
	}
	for(int i=1;i<=n;i++){
		maxx_and=max(maxx_and,f[i]);
	} 
	cout<<maxx_and;

	return 0;
}
