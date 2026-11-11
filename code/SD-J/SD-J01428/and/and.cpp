#include<iostream>
#include<cstdio>
#include<algorithm>
const int N=2e5+5;
using namespace std;
int a[N],n,m,cnt;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	cnt=a[1];
	for (int i=2;i<=m;i++)cnt&=a[i];
	cout<<cnt;
	return 0;
}
