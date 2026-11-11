#include<bits/stdc++.h>
using namespace std;
bool cmp(long a,long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long a[n+1];
	for(long i=1;i<=n;i++){
		cin>>a[i];		
	}
	sort(a+1,a+1+n,cmp);
	cout<<a[m];
	return 0;
	}
