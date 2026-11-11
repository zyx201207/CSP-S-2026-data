#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,a[N],pre[N],dp[N],ans=1,cnt=1,yjy,xyy,msx[N],pre2[N],dp2[N];//,ba;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		pre[i]=a[i]-a[i-1];
		//ba+=abs(pre[i]);//第i个元素和前一个元素的差 
	}
	//ba/=n;
	dp[1]=0;//dp[a[2]]=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(abs(pre[i])>m&&abs(pre[i+1])>m){
			dp[i]=0;
			cnt=1;
			msx[i]=1;
			continue;
		}
		dp[i]=dp[i-1]+cnt*pre[i];//将第i个元素之前的所有元素变成第i个元素的次数 
		cnt++;
	} 
	for(int i=1;i<=n;i++){//找到最大的dp[a[i]]
		if(dp[i]<=m){
			//1 2 4 8 9
			if(dp[i]==0&&i!=1&&msx[i]==1){
				yjy=yjy+i-1;
				msx[i]=0;
				//cout<<a[i]<<" ";
			}
			xyy=i-yjy;
			if(xyy>=ans){
				ans=xyy;
			}
			/*maxx=dp[a[i]];
			ans=i;*/
			/*int cnt=i;
			if(a[i]>0){
				cnt+=(m-dp[a[i]])/a[i];
			}
			if(cnt>ans){
				ans=cnt;
				man=a[i];
			}*/
		}
	} 
	cnt=1;yjy=0;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		pre[i]=abs(a[i]-a[i-1]);
		//ba+=abs(pre[i]);//第i个元素和前一个元素的差 
	}
	//ba/=n;
	dp[1]=0;//dp[a[2]]=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(abs(pre[i])>m&&abs(pre[i+1])>m){
			dp[i]=0;
			cnt=1;
			msx[i]=1;
			continue;
		}
		dp[i]=dp[i-1]+cnt*pre[i];//将第i个元素之前的所有元素变成第i个元素的次数 
		cnt++;
	} 
	for(int i=1;i<=n;i++){//找到最大的dp[a[i]]
		if(dp[i]<=m){
			//1 2 4 8 9
			if(dp[i]==0&&i!=1&&msx[i]==1){
				yjy=yjy+i-1;
				msx[i]=0;
				//cout<<a[i]<<" ";
			}
			xyy=i-yjy;
			if(xyy>=ans){
				ans=xyy;
			}
			/*maxx=dp[a[i]];
			ans=i;*/
			/*int cnt=i;
			if(a[i]>0){
				cnt+=(m-dp[a[i]])/a[i];
			}
			if(cnt>ans){
				ans=cnt;
				man=a[i];
			}*/
		}
	} 
	cout<<ans;
	return 0;
}
