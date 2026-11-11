#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100000000];
int num,num1;
int main(){
	freopen("crystal.in",r,stdin);
	freopen("crystal.out",w,stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		num1=0;
		while(a[i+num1]-a[i]<=m&&i+num1<=n){
			num1++;
		}
		num=max(num1,num);
	}
	cout<<num;
	return 0;
}
