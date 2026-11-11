#include<iostream>
#include<queue>
using namespace std;
int n,m;
int c[500010];
int sum[300010];
queue<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>c[i];
	}
	for(int I=1;I<=n;++I){
//		while(!q.empty()) q.pop();
		int desk[500010];
		int l=1,r=0;
		for(int i=I;i<=n;++i){
			q.push(c[i]);
		}
		while(!q.empty()){
			int e=q.front();
			q.pop();
			for(int i=l;i<=r;++i){
				if(desk[i]==e){
					while(r>=i){
						--r;
					}
					break;
				}
			}
			desk[++r]=e;
		}
		for(int i=l;i<=r;++i){
			sum[desk[i]]++;
		}
//		for(int i=l;i<=r;++i){
//			cout<<desk[i]<<" ";
//		}
//		cout<<"\n";
	}
	for(int i=1;i<=m;++i){
		cout<<sum[i]<<" ";
	}
	return 0;
}
/*


梨花香 缠裹衣角掠过熙攘
复悄入红帘深帐
听枝头黄鹂斗曲儿 细风绕枝棠
坐船舫 兰浆拨开雾霭迷茫
不觉已一日过半 
xxxxxxx xxxxx
xxxxxx xxxxx xxxxxxxxx
xxxxx xxxxxxx

在这老街回眸 烟雨中追溯我是谁
只消暮雨点滴 便足以粉饰这是非
待这月色涌起 谁人轻叩这门扉
苔绿青石板阶 斑驳了流水般岁月
小酌三盏两杯 理不清缠绕的情结
在你淡漠眉间 瞥见离人的喜悲霜雪

··· 

三月梨花雪 几朝开了又拜
笔锋走黑白 xxxxxx
xxxxx xxxxxxx
而我又在待何人

··· 


*/
