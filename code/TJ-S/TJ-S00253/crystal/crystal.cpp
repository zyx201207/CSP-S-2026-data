#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<cmath>
#include<cstring> 
#define int long long 
using namespace std;
/*
maxn
long long  signed 
多测清空 
freopen不要注释 
*/
const int maxn=5e5+5;
int n,m,a[maxn],num,sum,ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	int l=1;
	for(int i=1;i<=n;i++){
		sum+=num*(a[i]-a[i-1]);
		num++;
		if(sum>m){
			while(sum>m){
				sum-=(a[i]-a[l]);
				num--;
				l++;
			}
		}
		ans=max(ans,num);
	}
	printf("%lld",ans);
	return 0;
} 
