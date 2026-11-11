#include<bits/stdc++.h>
using namespace std;
long long a[200003];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
	    cout<<0;
	    return 0;
	}
	sort(a+1,a+n+1,cmp);
	long long ans=a[1];
	for(int i=2;i<=m;i++){
		ans=ans&a[i];
	}
	printf("%lld",ans);
	return 0;
}
