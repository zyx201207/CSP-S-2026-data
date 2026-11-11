#include<bits/stdc++.h>
//#define int long long
using namespace std;
int n,m,a[500010],maxx=-0x3f3f3f3f3f3f3f3f,minn=0x3f3f3f3f3f3f3f3f,ans,tmp[500010];

bool check(int x){
	int sum=0;
	for(int i=1;i<=n;i++){
		if(x>a[i]){
			sum+=x-a[i];
		}
	}
	return sum>m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		minn=min(minn,a[i]);
	}
	sort(a+1,a+n+1);
	int l=minn,r=maxx,mid;
	while(l<=r){
//		cout<<l<<' '<<r<<endl;
		mid=(l+r)>>1;
		if(check(mid)){
			r=mid-1;
		}
		else l=mid+1;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=l) ans++;
	}
	cout<<ans;
//	for(int k=minn;k<=maxx;k++){
//		int dp[100010]={0};
//		for(int i=1;i<=n;i++){
//			if(a[i]<=k) tmp[i]=k-a[i];
//			else tmp[i]=0x3f3f3f3f3f3f3f3f;
//		}
//		for(int i=1;i<=n;i++){
//			for(int j=k;j>=tmp[i];j--){
//				dp[j]=max(dp[j],dp[j-tmp[i]]+1);
//			}
//		}
//		ans=max(ans,dp[k]);
//	}
//	cout<<ans;
	return 0;
}
/*
14:25 连续换了两个鼠标都是坏的
一个不能滚轮
一个移动抽搐
力竭了

14:58 发现貌似不是贪心

15:22 机房里好tm热啊
感觉要中暑了
头很晕

15:35 为什么程序运行不了啊
返回3221225725

15:43 为什么这个电脑的栈怎么小啊
main里连1e6的数组都开不出来
贪心假就假吧
背包做不了了

预计15pts 
*/
