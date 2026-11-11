#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
long long n,m,a[N],ad[N];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
		cin>>a[i];}
	}sort(a+1,a+1+n,cmp);
	ad[1]=a[1];
	for(int i=1;i<=m;i++){
		ad[i]=ad[i]&a[i+1];
	}cout<<ad[m];
	return 0;
}
