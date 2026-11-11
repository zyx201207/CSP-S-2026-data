#include<bits/stdc++.h>
using namespace std;
long long m,n,a[10000000],sum=0;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	sum=a[0];
	for(long long i=1;i<m;i++){
		
		sum=sum & a[i];
	}
	cout<<sum;
	return 0;
} 
