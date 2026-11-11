#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],c;
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i <= n;i++)
		cin>>a[i];
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n-i;i++){
		if(j<i&&(a[j] & a[i] > c))
			c = a[j] & a[i];
		if(j>=i&&(a[j] & a[i] > c))
			c = a[j] & a[i];
		}
	}
	cout<<c;

	return 0;
}
