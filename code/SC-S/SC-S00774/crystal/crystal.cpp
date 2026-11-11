#include<bits/stdc++.h>
using namespace std;
int n,m,sum;
int main(){
	freopen("crysal.in","r",stdin);
	freopen("crysal.out","w",stdout);
	cin>>n>>m;
	int a[n],c[n];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=2) c[i-1]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++){
		sum=2*sum+c[i];
		if(sum+c[i+1]>m||sum==m&&c[i]!=c[i+1]){cout<<i+1;break;}
	}
	return 0;
}