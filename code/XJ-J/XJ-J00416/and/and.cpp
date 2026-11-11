#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N];
long long sum;
bool cmp(long x,long y){
	if(x!=y){
		return x>y;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	sum=a[1];
	for(int i=2;i<=m;i++){
		sum&=a[i];
	}
	cout<<sum;
	return 0;
}