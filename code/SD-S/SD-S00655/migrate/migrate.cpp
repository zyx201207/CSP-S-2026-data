#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+1;
int n,d,a[maxn],ans=0;
int minn=114514,num;
int dfs(int x,int y,int l){
	if(x==y){
		if(l<minn)minn=l,num=0;
		if(l==minn)num++;
		return 0;
	}
	for(int i=x+1;i<=y;i++){
		if(a[i]-a[x]<=d){
			l++,dfs(i,y,l),l--;
		}
	}
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				minn=114514,num=0;
				int k=dfs(i,j,0);
				if(num==2)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
曾许下心愿，等待你的出现。
褪色的秋千，有本书，会纪念。
我循着时间，捡起梦，的照片。
童话还没有兑现，却需要说再见。
如果有一天，岁月晕开了书页。
请把我模糊的字迹当作笑脸。
很久前，想象，今天，画面。
哭着笑着告别，
陌生的情节，熟悉的侧脸都重叠，哦~
出发前，无数，星光，缱绻，
有回忆落在指尖。
当世界向前，我会在原地，流连。
当漪涟，一点，一滴，出现。
轻轻去向天边，
不管多遥远，都是追不上的思念，哦~
会不会，可能，还能，相见，
再回头只看一眼。
当漪涟，消散，万千，不见，
永恒和瞬间都被爱意成全，
我的明天叫做昨天，哦~
要相信，浪漫，一如，初见，
请笑着向我告别，
最后这一页，就让它无言。
我会在扉页，等待你续写，起点~
*/
