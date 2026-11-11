#include<bits/stdc++.h>
using namespace std;
struct xc{
	int a;
	int b;
};
bool cmp(xc a,xc b){
	if(a.a==b.a) return a.b>b.b;
	else return a.a>b.a;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	long long h=0;
	int m;
	cin>>n>>m;
	xc a[n+10]={};
	for(int i=1;i<=n;i++){
		int j;
		cin>>j;
		a[i].b=j;
		while(j>0){
			a[i].a+=j%2;
			j/=2;
		}
	}
	sort(a+1,a+n+1,cmp);
	h=a[1].b;
	for(int i=1;i<=m;i++){
		h=h&a[i].b;
	}
	cout<<h;
	return 0;
}
