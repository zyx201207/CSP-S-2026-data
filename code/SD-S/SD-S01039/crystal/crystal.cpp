//14:32 开题！比上午快多了
//		为什么今天是 12.25 
//14:33 有点像贪心
//		这键盘比上午的还难用
//		上午忘记留 uid 了，放 S 组吧 1430229 
//14:44 哦不不不不不是双指针 (wzq 是预言家，J 和 S 都预言对了)
//14:50 哦我的天天天天天我不会这么快就把 T1 切了吧
//14:52 I got 100pts! This is my dream! I realize it so early!
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int ans=LLONG_MIN;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int l=1,r=1;
	int c=0;
	while(l<=r&&r<=n){
		if(c<=m){
			ans=max(ans,r-l+1);
			r++;
			c+=(a[r]-a[r-1])*(r-l);
		}else{
			l++;
			c-=a[r]-a[l-1];
		}
	}
	cout<<ans;
	return 0;
} 
//100pts 
