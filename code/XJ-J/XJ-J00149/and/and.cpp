#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200005]={};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long num=a[n];
	for(int i=n-1;i>n-m;i--){
		num=a[i]&num;
	}
	cout<<num;
	return 0;
}

