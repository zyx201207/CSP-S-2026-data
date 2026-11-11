#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005];
bool cmp(long long x,long long y){
	if(x==y){
		return x==y;
	}
	return x<y;
}
int main(){
	freopen("and.in","w",stdin);
	freopen("and.out","r",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	cout<<a[m-1];
	return 0;
}
