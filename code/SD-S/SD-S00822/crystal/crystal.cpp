#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
bool f=1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int minn=0x3f3f3f3f;
	int maxn=0xcfcfcfcf;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		minn=min(minn,a[i]);
		maxn=max(maxn,a[i]);
	}
	int d=a[2]-a[1];
	int summ=0,ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]-a[i-1]!=d&&i!=1) f=0;
		if(summ+abs(a[i]-maxn)>=m) break;
		summ+=abs(a[i]-maxn);
		ans++;
//		cout<<"?";
	}
	if(ans==n){
		cout<<n;
		return 0;
	}
	else if(f==1){
		int k=(n+1)/2;
		int cnt=0,ans=0;
//		cout<<"ak"<<a[k]<<'\n';
		for(int i=1;i<=n;i++){
			
			if(a[i]<=a[k]){
				if(cnt+abs(a[i]-a[k])>m) break;
				cnt+=abs(a[i]-a[k]);
				ans++;
			}
		}
		cout<<ans;
	}
	else{
		int anss=0;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			int k=i;
			int cnt=0,ans=0;
			for(int j=1;j<=n;j++){
				if(a[j]<=a[k]){
					if(cnt+abs(a[j]-a[k])>m) break;
					cnt+=abs(a[j]-a[k]);
					ans++;
				}
			}
			anss=max(anss,ans);
		}
		cout<<anss;
	}
	return 0;
}
/*
童年回忆美好却残酷，
因为你会在不知不觉中忘却，
忘却其声音，
忘却其相貌，
最终只会落得，
空虚、遗憾。
每当你再次回望，
温暖总会涌上心头，
就第一次那样，
可，
都是从前了。
你已无法回眸，
只能向前，
将微笑面对阳光，
将背影留给黑暗。
想象自己被爱过，
想象自己被人在意，
不过，
想象终有落空的一天。
从那天起，你我此生便再无交集。

寒，
是世界的主旋律，
该来的总会来，
该走的，
也不会留恋，
不会回首。
你我的相遇，要从夏日说起。
夏日的蝉鸣，四人的欢笑；
低落的汗水，沁凉的水；
开学的问好，同桌的相遇；
整齐的书桌，整齐的笔袋；
课间的聊天，生日的互换；
那时的承诺，永远的誓言；
唯一的心愿，唯一的你；
温柔的关心，亲切的称呼；
珍贵的修正带，珍贵的笔；
永恒的珍藏，爱情的见证；
都是梦，该醒了； 
手指的伤疤，尖锐的文字；
曾经的你，曾经温柔的你；
该走了，别回头；
别回味，太扎心；
誓言不过是玩笑，
真情不过流水，
本来的甜蜜，
不过相思。
凌晨已到，
该回原点了，
就当什么也没发生——
不可能！
相识的一年二月三周零四日，
相恋的八月零二十三日，
只剩下零。
唯有零，
是亘古不变的。
唯有我，
是一心爱你的。
回忆仍是回忆，
莫回首，面向前。
最后，两眼泪汪汪，轻声贴在你耳边，“姐姐，再见！”.... 
*/
