#include<bits/stdc++.h>
using namespace std;
int s[10001];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int a[100001];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int f=a[1];
	while(f>0){
		int j=1;
		s[j]=f%2;
		f=f/2;
		j++;
		cout<<j;
	}
	return 0;
}
