#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+10;
int a[maxn],cnt=0; 
bool cmp(int a,int b){
	return a>b;
} 
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=k;i++){
		a[i]&=a[i-1];
	}
	printf("%lld",a[k]);
	return 0;
}
