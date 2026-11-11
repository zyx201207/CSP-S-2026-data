#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y){
	return x>y;
}
long long n,m,a[200001],b=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	b=a[1];
	for(int i=2;i<=m;i++){
		b&=a[i];
	}
	cout<<b;
    return 0;
}
