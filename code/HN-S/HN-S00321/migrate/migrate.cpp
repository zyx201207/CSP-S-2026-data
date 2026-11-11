/*
《当那一天来临》 
这是一个晴朗的早晨
鸽哨声伴着起床号音
但是这世界并不安宁
和平年代也有激荡的风云

准备好了吗，士兵兄弟们
当那一天真的来临？
放心吧祖国
放心吧亲人
为了胜利我要勇敢前进！

看那军旗飞舞的方向
前进着战车舰队和机群
上面也飘扬着我们的名字
年轻士兵渴望建立功勋

准备好了吗，士兵兄弟们
当那一天真的来临？
放心吧祖国
放心吧亲人
为了胜利我要勇敢前进！

准备好了吗，士兵兄弟们
当那一天真的来临？
放心吧祖国
放心吧亲人
为了胜利我要勇敢前---进！
*/
/*
这封信将寄给最喜欢自己的我
想要就竭力争取
无论走到哪里都会真实闪耀
所以务必把它交给你
				----节选自《今天不是明天》 
*/
#include<bits/stdc++.h> 
using namespace std;
int c,t,n,d;
int dis[6000][6000],cord[6000];
map<pair<int,int>,pair<int,int> >mp;
void dfs(int x,int sum,const int start_point){
	if(x!=start_point){
		if(mp[{start_point,x}].first>sum){
			mp[{start_point,x}].first=sum;
			mp[{start_point,x}].second=1;
		}
		else if(mp[{start_point,x}].first==sum)mp[{start_point,x}].second++;
	}
	for(int i=x+1;i<=n;i++){
		if(dis[x][i]>0)dfs(i,sum+dis[x][i],start_point);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	cin>>c>>t;
	while(t--){
		memset(dis,0,sizeof(dis));
		memset(cord,0,sizeof(cord));
		mp.clear();
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>cord[i];
			for(int j=1;j<i;j++){
				if(cord[i]-cord[j]<=d)dis[j][i]=cord[i]-cord[j];
			}
		}
		for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)mp[{i,j}]={0x3f3f3f3f,0};
		for(int i=1;i<=n;i++){
			dfs(i,0,i);
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(mp[{i,j}].second==2)ans++;
				//cout<<mp[{i,j}].second<<" ";
			}
			//cout<<endl;
		}
		/*for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)cout<<dis[i][j]<<" ";
			cout<<endl;
		}*/
		cout<<ans-1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
