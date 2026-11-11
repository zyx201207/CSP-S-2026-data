#include <bits/stdc++.h>
using namespace std;
int a[5000000];
bool cmp(int a,int b){
	if(a>b) return true;
	else return false;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
    sort(a+1,a+n+1,cmp);
    int maxn=a[1];
	for(int i=2;i<=m;i++){
		maxn = maxn & a[i];
	}
	cout<<maxn;
	return 0;
}
