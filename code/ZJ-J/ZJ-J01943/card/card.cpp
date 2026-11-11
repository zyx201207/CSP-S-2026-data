#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
const int maxm=3e5+5;
int n,m;
int a[maxn],pos[maxm],quiet_yes[maxn];//依旧不会取名
//quiet_yes = 静yes = 静夜思
int ans[maxm];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;cin>>a[i++]);//hyw输入
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			pos[i]=-1;
		}
		int now_pos=1;
		for(int j=i;j<=n;j++){
			if(pos[a[j]]==-1){
				pos[a[j]]=now_pos;
			}
			else{
				for(int k=pos[a[j]]+1;k<now_pos;k++){
					pos[quiet_yes[k]]=-1;
				}
				now_pos=pos[a[j]];
			}
			quiet_yes[now_pos++]=a[j];
		}
		for(int j=1;j<now_pos;j++){
			ans[quiet_yes[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
}
/*
OK啊，留给T4的时间还有1h

10月第一件事，打开NOI官网
310金币一次，我非常癫狂
devc++主国，visual studio盟国
2个freopen
还有俯冲骗分哥，谁能如何我？
编不下去了
以防你不知道，上面的文本改编自《沟槽的美芬》

先拿模拟骗个分
你说我要是上不了迷惑行为大赏不就亏大了？
浪费了至少有20min在这上面啊
100年内没人看得懂我的代码
6，错了
#1 in
4 3
1 2 1 3
#1 out
3 1 4
#2 in
10 3
3 1 2 1 3 2 3 1 2 1
#2 out
10 3 3
funk ccf(有意为之)
froepen
freoepn("treval.in","r",stdin);
freoepn("treval.out","w",stdout);
*/
