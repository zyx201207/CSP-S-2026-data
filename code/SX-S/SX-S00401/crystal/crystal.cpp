#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],n,m;
map<int,int>mp; // mp[i]表示水晶密度为i的数量

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		mp[a[i]]++;
	}
	// 对于i，若a[i]>当前选定的密度，则一定不可能被选定
	// 故当前问题被转化为找到一个ans使得在<ans的数中，靠近ans的量尽可能多
	// 可以想到是需要巧妙地预处理
	// 用mp的桶思想吗？
	// 肯定不能做到AC，但写出来试试

	// 容易想到，可以转化的一定是一个区间
	// 用双指针（看起来像是滑动窗口）使这个区间尽可能大？好像可以哎！
	sort(a+1,a+n+1);
	// 每次r都+1，然后看看有什么需要释放的部分
	int l=1,r=1,cnt=1,sum=0; // 初始时区间就是一个数
	// 先看看从1~几是可以的
	while(r<=n&&sum<=m){
		if(sum+(a[r+1]-a[r])*cnt<=m){
			sum=sum+(a[r+1]-a[r])*cnt;
			r++,cnt++;
		}else{
			break;
		}
	}
	int ans=cnt;
	// 左闭右开的问题把自己绕进去了。。。
	// 算了还是两个闭区间吧
	while(r<=n){
		sum=sum+(a[r+1]-a[r])*cnt;
		r++; cnt++;
		while(sum>m){
			sum-=a[r]-a[l];
			l++;
			cnt--;
		}
		ans=max(ans,cnt);
	}
	cout<<ans<<endl;
	return 0;
}