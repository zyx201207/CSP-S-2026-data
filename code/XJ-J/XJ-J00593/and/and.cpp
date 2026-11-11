#include <bits/stdc++.h>
using namespace std;
int m,n;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long x,max=0,nn=n;
	while(a[nn-m+1]>=max){
		x=a[nn];
		for(int i=nn-1;i>n-m;i--){
			long long y=x;
			x=y&a[i];
		}
		if(x>max) max=x;
		nn--;
	}
	cout<<max<<endl;
	return 0;
}