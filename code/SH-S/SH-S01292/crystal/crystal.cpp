#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5,inf=0x3f3f3f3f; 
long long n,m,a[maxn],b[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int flag1=1,flag2=1,xx;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(i!=1){
			if(a[i]!=a[i-1]){
				flag1=0;
			}
		}
		if(i>2){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
				flag2=0;
			}
		}
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;--i){
		int ans=(i-1)*a[i];
		if(flag1==1){
			ans=(1+i)*i/2;
		}else if(flag2==1){
			ans=(a[1]+a[i])*i/2;
		}else{
			for(int j=i-1;j>=1;--j){
				ans-=a[j];
			}
		}
		if(ans<=m){
			cout<<i;
			break;
		}
	}
	return 0;
} 
