#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010];
long long f[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	memset(f,0,sizeof(f));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=min(m,i);j>=1;j--){
			if(j==1) f[j]=max(f[j],a[i]);
			else f[j]=max(f[j],f[j-1]&a[i]);
		}
	}
	cout<<f[m];
	return 0;
}
