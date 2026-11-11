#include <bits/stdc++.h>
using namespace std;

int _find(int card,int desktop[100005],int nowd){
	for(int f=1;f<nowd;f++){
		if(f==card){
			return f;
		}
	}
	return nowd;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int a[100005];
	cin>>n>>m;
	int last[100005]={};//记录最后一张牌 
	for(int i=1;i<=n;i++) cin>>a[i];//从1开始 后面可直接调用 
	for(int i=1;i<=n;i++){//记录局数 
//		int nowc=i;//记录现在的牌编号,在下层for中定义 以舍去
		int desktop[100005]={};//桌面上的卡牌，每开始一局重置
		int nowd=1;//定义桌面上第一个空位编号（方便添加元素）
		for(int nowc=i;nowc<=n;nowc++){//开始出牌 
			int nowcard=a[i];
			int cl;
			for(cl=_find(nowcard,desktop,nowd);cl<=nowd;cl++){
				desktop[cl]=0;
			}
			nowd=_find(nowcard,desktop,nowd)+1;  
			desktop[_find(nowcard,desktop,nowd)]=nowcard;
		} 
		last[desktop[nowd-1]]++;
	}
	for(int i=1;i<=m;i++) cout<<last[i]<<' ';
}
































