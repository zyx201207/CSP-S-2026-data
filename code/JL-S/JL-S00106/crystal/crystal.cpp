#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[500010];
int main(){
	freopen("crtstal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n-1&&m>0;i++){
		m-=(a[i+1]-a[i])*(i+1);
		for(int j=0;j<=i;j++)a[j]=a[i+1];
	}
	int cnt=1;
	for(int i=1;i<n;i++){
		if(a[i]==a[i-1])cnt++;
		else break;
	}
	cout<<cnt;
	return 0;
}
