//前缀和+贪心+二分答案  b[i]-b[j]+k=(i-j)a[i],k<=m; 
#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m;
long long a[500005],b[500005]={0};
bool cmp(long long a,long long b){
	return a<b;
}
void work(){
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n,cmp);//样例不一定有序 
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	ans=1;
	/*for(int i=n;i>=1;i--){
		for(int j=i-1;j>=0;j--){
			long long num=i-j;
			long long sum=b[i]-b[j];
			long long k=a[i]*num-sum;
			int t=num;
			if(k<=m){
				ans=max(ans,t);
			}
		}
	}*/
	for(int i=n;i>=2;i--){
		int l=1,r=i-1;
		while(l<=r){
			int mid=(l+r+1)/2;
			long long num=i-mid+1;
			long long sum=b[i]-b[mid-1];
			long long k=a[i]*num-sum;
			int t=num;
			if(k<=m){
				ans=max(ans,t);
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
	}
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	work();
	printf("%d",ans);
	return 0;
}
