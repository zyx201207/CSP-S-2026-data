#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=5e5+10;
const int M=3e5+10;
int a[N];
int c[M];
int b[N];
int bh[M];
int sum[M];
bool rsc(int x,int y){
	for(int i=1;i<=y;i++){
		if(b[i]==x){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){//n轮游戏
		memset(b,0,sizeof(b));
		memset(bh,0,sizeof(bh));//初始化 
		int q=1;//桌子上的牌编号 
		for(int i=k;i<=n;i++){//第k张牌开始~n结束 
			if(rsc(a[i],q)){//若桌上有点数为i的牌 
				q=bh[a[i]];//后面从这里开始摆 
				for(int w=bh[a[i]];w<=q;w++){//从i开始删完  
					bh[b[w]]=0;//重置编号 
					b[w]=0;//删掉 
				} 
			}
			b[q]=a[i];//放到最右侧 
			bh[a[i]]=q;//记录此点数的牌在桌上的位置 
			q++;//下一个位置 
			
		}
		for(int e=1;e<=q;e++){//累计
			if(b[e]<=0){
				continue;
			}
			cout<<b[e]<<" ";
			sum[b[e]]++;//这轮桌上留下的牌 
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		 cout<<sum[i]<<" "; //输出 
	}
	cout<<endl;
	return 0;
}
//7199
