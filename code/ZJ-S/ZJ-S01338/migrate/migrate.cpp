#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int a[N];
bool A(int a[N],int n){
	int x1=a[2]-a[1],x2=1;
	for(int i=3;i<=n;i++)
		if(a[i]-a[i-1]==x1)
			x2++;
	if(x2==n-1)
		return true;
	return false;
}
int A1(int x,int a[N],int n,int d){
	if(d<2*x||d>=(n-1)*x)
		return 0;
	int cnt=d/x+2;
	return n-cnt+1;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if(A(a,n))
			cout<<A1(a[2]-a[1],a,n,d)<<endl;
	}
	return 0;
}