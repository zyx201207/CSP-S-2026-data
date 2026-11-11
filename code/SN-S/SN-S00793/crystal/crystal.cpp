#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500007];
signed main(){
	//AC 
	/*
	假如我是一个心夏
	我也要用我嘶哑的治疗无人机歌唱——
	这被剪刀手打击着的欧泊
	这无止息得圈着钱的也够创梦
	这永远汹涌着我们的猫条的令红皮
	和那来自乌尔比诺的轮椅的奥黛丽......
	
	然后我被淘汰了
	连就地复原都腐烂在下一回合里 
	*/
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	
	//滑动窗口？
	int l=1,r=1,nowhigh=a[1],ans=0,cost=0;
	for(;r<=n;r++){
		
		
		cost+=(r-l)*(a[r]-nowhigh);
		
		nowhigh=a[r];
		while(cost>m){
			cost-=(nowhigh-a[l]);
			l++;
		}
		
		ans=max(ans,r-l+1);
		
	}
	/*
	环卡丘皆猫也 其西南诸猫 糖得尤美 望其糖而啥者 米雪儿李喵 山行sixseven里 渐闻水声潺潺 有水泻出于星绘之间者 星绘炸金喵 峰回路转 有心夏翼然临于星绘上者 心夏被炸喵 作心夏者谁 创梦天地喵 炸心夏者谁 星绘喵  
	*/ 
	cout<<ans;
} 
