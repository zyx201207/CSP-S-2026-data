#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+400;
long long n,m,a[N],sum,maxx,k,l;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	sum=a[1];
	
	for(int j=2;j<=min(n,m);j++){
		sum=sum&a[j];
	}
	cout<<sum;
} 
