#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
bool cmp(int a,int b){
	return a>b;
}
long long k;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	k = a[0];
	for(int i = 1;i<m;i++){
		k = k&a[i];
	}
	cout<<k;
}
