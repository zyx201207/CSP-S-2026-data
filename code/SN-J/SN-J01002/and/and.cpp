#include<bits/stdc++.h>
using namespace std;
int n,m,mark;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long a[n+5];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	mark=a[0];
	for(int i=1;i<m;i++){
		mark=mark&a[i];
	}
	cout<<mark;
	return 0;
}
