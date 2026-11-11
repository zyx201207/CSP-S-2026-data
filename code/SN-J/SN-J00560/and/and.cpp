#include<bits/stdc++.h>
using namespace std;
int n,m,sum;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int a[n+10]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	sum=a[0];
	for(int i=0;i<m;i++){
		sum=sum&a[i];
	}
	cout<<sum;
	return 0;
}
