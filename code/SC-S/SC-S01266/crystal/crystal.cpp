#include<bits/stdc++.h>
using namespace std;
int n,m,sum;
long long a[500005],b[500005];
int main(){
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
		if(i*a[i]-b[i]<=m) sum=i;
		else break;
	}
	cout<<sum;
	return 0; 
}