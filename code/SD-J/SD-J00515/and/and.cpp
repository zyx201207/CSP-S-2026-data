#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[200010];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		int mx=-1;
		for(int i=0;i<n;i++){
			if(a[i]>mx){
				mx=a[i];
			}
		}
		cout<<mx;
	}else if(m==2){
		int mx=-1;
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				if((a[i]&a[j])>mx){
					mx=a[i]&a[j];
				}
			}
		}
		cout<<mx;
	}else if(m==n){
		int num=a[0];
		for(int i=1;i<n;i++){
			num=num&a[i];
		}
		cout<<num;
	}else if(m==n-1){
		int mx=-1;
		for(int i=0;i<n;i++){
			long long num=a[0];
			if(i==0){
				num=a[1];
			}
			for(int j=0;j<n;j++){
				if(i==0&&(j==1||j==0)){
					continue;
				}
				if(i==j){
					continue;
				}
				num=num&a[j];
			}
			if(num>mx){
				mx=num;
			}
		}
	}else if(n>m){
		cout<<n-m-1;
	} 
	return 0;
}
/*
//想上迷惑行为大赏 
CSP-J游记
Day -inf
初赛。
报了-J和-S 
-J:
CCF居然把BFS出进题了？不管了原地开始大模拟
赛后和xzt一起走，我提到那道BFS的题，他说可以用洪水填充法，气笑了 
喜提67.5 
-S:
开考。
啊啊啊题好难
连蒙带猜 
~~绝大部分都是猜的~~ 
喜提41.5,再一次气笑了
Day -1 10.30
8：00 出发
路上和xzt一起坐，还没出发时打开了我的电脑，30分钟后 教练开始点名了，我的电脑关机了 (晕)
xzt也带了电脑，路上一块下液态围棋，玩游戏 ，1h后，xzt的电脑光荣的完成了使命，关机了~~轻松绷住~~；
剩下的时间就看yhr和yzh玩PVZ，羡慕+1；
12：30到达日照
去吃饭，菜挺好吃，好评； 
13：30到达房间
和xzt拼房，前 2h在玩MC,刷bilibili，然后做题
18：00下楼吃饭............
luogu uid:1556427
求壶关 
 
*/
