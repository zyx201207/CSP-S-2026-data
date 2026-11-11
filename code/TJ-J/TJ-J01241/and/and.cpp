#include<bits/stdc++.h>
using namespace std;
long long a[2*100000+10];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	long long sum=a[1];
	for(int i=2;i<=m;i++){
		sum&=a[i];
	}
	cout<<sum;
	//and=&
	return 0;
}
