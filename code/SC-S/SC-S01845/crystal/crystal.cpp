#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=5e5+2;
int n;//水晶数量
ll a[MAXN];//每一个水晶的能量值
ll q[MAXN];//排序后的水晶能量值前缀和 
ll m;//操作次数
int ans=0;//答案
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//in
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	//预处理 
	sort(a+1,a+1+n);//升序 
	for(int i=1;i<=n;i++)
		q[i]=(q[i-1]+a[i]);
	//求解 
	for(int i=1;i<=n;i++){
		//以i为结尾的最大合并量
		int l=1,r=i;
		while(l<r){
			//越往前越不满足 
			int mid=(l+r)/2;
			//从mid到i之间的操作数(ll)sum是否大于m 
			int len=i-mid+1;//区间长度 
			ll sum=(1ll*a[i]*len-(q[i]-q[mid-1]));//q[i]-q[mid-1]区间的总量 
			if(sum>m){
				//超出操作限制
				l=mid+1; 
			}else{
				r=mid;
			}
		}
		ans=max(ans,i-l+1);
	}
	printf("%d",ans);
}