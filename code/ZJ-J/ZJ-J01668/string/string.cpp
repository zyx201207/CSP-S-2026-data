#include <bits/stdc++.h>
using namespace std;
const int N=1e5*2+5;
struct node{
	int number;
	string name;
}a[N];
int n;
long long ans=0;
long long c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].number>>a[i].name;
		c[i]=c[i-1]+a[i].number;
	}
	long long nl=1,nr=n;
	for(long long i=1;i<=c[n]/2;i++){
		long long l=i,r=c[n]-i+1;
		if(l>c[nl]) nl++;
		if(r<=c[nr-1]) nr--;
		if(a[nl].name!=a[nr].name) ans++;
	}
	cout<<ans;
	return 0;
}