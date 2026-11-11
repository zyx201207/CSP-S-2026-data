/*
Author:蝴蝶(lg uid 663638)
Start Coding: 14:30
Finish Coding: 14:33
Finish Debugging: 14:37
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,l,r,mid,res,a[500005],s[500005];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		l=1;r=i;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(a[i]*(i-mid+1)-s[i]+s[mid-1]>m)l=mid+1;
			else{res=mid;r=mid-1;}
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans;
}
/*
在 星海漫过 沉默
指尖流苏 任苍穹闪烁
裙摆似你身影环绕我
伸手却无法触摸

辗转寻觅照耀
你留下的记号
慢慢银河中再找不到
深深刻下裂痕
只留下了我一人
与思念的倾盆

仿佛在耳边呼唤过的声音
来自遥不可及的距离
裙摆突然央企思绪将我囚禁
埋葬在永夜里
星辰幻化在手心化作沙砾
默数再次相会的日期
不知何年何月才能再次想起
你运行的轨迹

听 眼角划过 流星
滑落胸膛 心脏在灼伤
模糊的你像一个陷阱
忘了痛还在沉浸

仿佛为自己许下过的约定
残留无法辨认的字迹
还在幻想有奇迹将伤痕抚平
直到自我抽离
夜空星座伴耀眼裙摆掠过
勾勒不出是你的轮廓
那尘封的爱意能否为你诉说
请你告诉我
情愿坠落在你的宇宙里
别再留下远去的背影
还来不及 为你 幻化做无形的光晕

——《莎图温的裙摆》 
*/ 
