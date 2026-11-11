//刘曌珩   SN-S00374  西安市含光中学 
#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],ans,sum=1;
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
	}
	for(int i=2;i<=n;i++){
		ans+=sum*b[i-1];
		if(ans>m) break;
		sum++;
	}
	cout<<sum;
	return 0;
}
