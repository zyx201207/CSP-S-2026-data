#include<bits/stdc++.h>
using namespace std;
long long a[200005];


bool cmp(long long x,long long y){
	return x>y;
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
	long long dii=a[1];
	for(int i=2;i<=m;i++){
		dii&=a[i];
	}
	cout<<dii;
	return 0;
} 
