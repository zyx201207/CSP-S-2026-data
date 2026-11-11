#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n;
ll m;
ll a[N];
ll s[N]; //前缀，快速求出差值 
int cnt=0;
int ans=0;
int l=1;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i]; //哎 
	
//	for(int i=1;i<=n;i++)printf("%lld ",a[i]);
	/*
	注意到操作的单调性 
	枚举每一颗,和前面的值比对，如果前面的值和当前的值差值之和小于m，那么答案加1一定更优 
	操作数可能为0？一定要从头开始吗？
	反悔贪心：排完序后，思路同上，但是如果这个差值大于m，就删掉这个序列的第一个点 
	
	*/
	for(int i=1;i<=n;i++){
//		printf("%lld %lld %lld \n",a[i]*ll(i-l+1),s[i],s[l-1]);
		ll val=a[i]*ll(i-l+1)-(s[i]-s[l-1]);
		if(val<=m){
//			printf("success! op=%lld\n",val);
			cnt++;
		}else{
//			printf("fail! op=%lld\n",val);
			while(val>m && l<i){
				l++,cnt--;
				val=a[i]*ll(i-l+1)-(s[i]-s[l-1]);
			}
//			printf("new_l:%d\n",l);
			cnt++;
		}
//		printf("val=%lld\n",val);
//		printf("l=%d\n",l);
//		printf("%d\n",i);
//		printf("a[%d]=%lld cnt=%d\n",i,a[i],cnt);
		ans=max(ans,cnt);
	}
	printf("%d\n",ans);
	
	return 0;
}
