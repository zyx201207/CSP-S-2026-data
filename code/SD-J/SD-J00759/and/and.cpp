#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200100];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=0;
	for(int i=30;i>=0;i--){
		sort(a+1,a+n+1,greater<int>());
		int sum=0;
		for(int j=1;j<=n;j++){
			if(a[j]&(1ll<<i))sum++;
		} 
		if(sum>=m){
			n=sum;
			ans+=1ll<<i;
		}
		for(int j=1;j<=sum;j++)
			if(a[j]&(1ll<<i))a[j]-=1ll<<i;
	}
	cout<<ans;
	return 0;
}
/*
前面部分见T2 
9:05 开T3 ，想到贪心思路（从最高位到最低位每一位都看一遍，第一步：从大到小排序；第二步：如果有这一位的数字数>=m，则通过改变n的方式删掉没有这一位的数字并把答案加上这一位；第三步：把有这一位的数字的这一位删掉），听到旁边有人电话手表被收的消息，为旁边的人的禁三感到可惜
9:13 fix:我怎么把a[j]第i位是不是1写成了a[j]|(1ll<<i)啊 
9:15 测完样例，AC 
*/ 
