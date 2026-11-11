#include<bits/stdc++.h>
using namespace std;

long long int n,m,a[500010],b[500010],c[500010];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(i!=1) b[i]=a[i]-a[i-1];  
		else b[i]=0;
		c[i]=c[i-1]+b[i]*(i-1);
		if(c[i]>m){
			cout << i-1;
			return 0;
		}
	}
	cout << n;

	return 0;
}