#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010],ma=-1,h;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	long long x=a[n];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(ma<a[j]&x){
				ma=a[j]&x;
				h=j;
			}
		}
		x&=a[h];
		a[h]=0;
		ma=-1;
	}
	cout<<x;
	return 0;
}
