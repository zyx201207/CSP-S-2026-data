#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,l,r,ans,a[N];
char c[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	l=1,r=n;
	for(int i=1;i<=n;++i) cin>>a[i]>>c[i];
	while(l<r)
	{
		if(c[l]==c[r])
		{
			if(a[l]<a[r]) a[r]-=a[l],l++;
			else if(a[l]==a[r]) l++,r--;
			else if(a[l]>a[r]) a[l]-=a[r],r--;
		}
		else
		{
			if(a[l]<a[r]) a[r]-=a[l],ans+=a[l],l++;
			else if(a[l]==a[r]) ans+=a[l],l++,r--;
			else if(a[l]>a[r]) a[l]-=a[r],ans+=a[r],r--;
		}
	}
	cout<<ans;
	return 0;
}
/*
自三峡七百里中，两岸连山，略无阙处。重岩叠嶂，隐天蔽日。自非亭午夜分，不见曦月。
至于夏水襄陵，沿溯阻绝。或王命急喧，有时朝发白帝，暮到江陵。其间千二百里，随乘奔御风，不以疾也。
春冬之时，则素湍绿潭，回清倒影。绝巘多生怪柏，悬泉瀑布，飞漱其间。清荣峻茂，良多趣味。
每至晴初霜旦，林寒涧肃。常有高猿长啸，属引凄异，空谷传响，哀转久绝。故渔者歌曰，“巴东三峡巫峡长，袁鸣三声泪沾裳。” 
*/
