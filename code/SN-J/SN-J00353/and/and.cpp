#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a , long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[200005];
	
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	long long sum=a[0];
	for(long long i=0;i<m;i++){
		sum=sum&a[i];
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
