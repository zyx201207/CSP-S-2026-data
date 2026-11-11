#include<bits/stdc++.h>
using namespace std;
int a[200010];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,num=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	num=a[1];
	for(int i=2;i<=m;i++)
	{
		num=a[i] & num;
	}
	cout<<num;
	return 0;
} 
