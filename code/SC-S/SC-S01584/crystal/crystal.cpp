#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f*x;
}
const int N=5e5+5;
int n,m,a[N],sum[N];
bool check(int x){
	int add=0;
	for(int i=1;i<=n;i++){
		add+=a[i];
		if(i<x)continue;
		add-=a[i-x];
		if(add+m>=x*a[i])
			return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid))
			l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
/*
------------------------------------------------

fropen,frepen,Genshin Impact,bits/stdc+++.h

------------------------------------------------

张雪峰老师，我还记得你，一句一句，把我拉出迷雾里。
张雪峰老师，我还记得你，那些年少的愁，你替我扛起。
你站在讲台上，把难题说得亮堂。
一支笔一块黑板，照见我眼里的慌。
你总把话说实在，像冬天一杯热汤。
不绕弯不装腔，把路给我摆在前方。
那时候我害怕，怕未来太长。
你一句别怂，我就敢往前冲。
张雪峰老师，我还记得你，一句一句，把我拉出迷雾里。
张雪峰老师，我还记得你，那些年少的愁，你替我扛起。
粉笔回落在肩上，像雪一样安静。
你笑着说前途远，别先把自己看轻。
多少个深夜回家，我还在翻那页纸。
你说过的每句话，都在我心里立起。
后来风吹过来，我也学会了。
不拖不退，往自己的山峰走。
（长伴奏）
如果有一天，我走得很远。
也会想起那间教室的光线。
想起你拍着桌子，说别怕吃苦。
说这条路总会有人走出去。
张雪峰老师，我还记得你，一句一句，把我拉出迷雾里。
张雪峰老师，我还记得你，你给我的勇气，我一直放在心里。

------------------------------------------------

I'm the one who asked you to send "I love Arrtan_73" to @Arrtan_73 in CSP-J 2025.
But few of you did this which made me very disappointed.
Now he've changed his ID to Methyl_CH3. You know what I mean.

------------------------------------------------

左边那个SC-S01586非常傻逼一直在哼歌

------------------------------------------------
*/