#include<bits/stdc++.h>
using namespace std;
long long n,m;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long a[n+5]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	long long num=a[1];
	for(int i=2;i<=m;i++){
		num=num & a[i];
	}
	cout<<num;
return 0; 
}
