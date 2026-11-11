#include<bits/stdc++.h>
using namespace std;
int n,m,hasa=1;
int a[500005],ans[500005],last[500005],vis[205];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])hasa=0;
	}
	if(n<=500){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				vis[j]=0;
			}
			for(int j=i;j<=n;j++){
				if(vis[a[j]]){
					int now=j-1;
					while(a[now]!=a[j]){
						vis[a[now]]--;
						now--;
					}
				}
				else{
					vis[a[j]]++;
				}
			}
			for(int i=1;i<=m;i++){
				if(vis[i]>0){
					ans[i]++;
				}
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	}
	if(hasa){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i-1])last[a[i-1]]=i-1;
		}
		last[a[n]]=n;
		for(int i=1;i<=m;i++){
			cout<<last[i]<<" ";
		}
	}
	return 0;
}
/*游记 by @menggongshushu (洛谷) 
8:00 进考场
8:05 第一次宣读考场纪律
8:15 第二次宣读考场纪律 
8:25 下发草稿纸 公布解压密码
8:30 正式开始 浏览一遍T1~T4
8:35 开T1
8:42 AC T1
8:45 开T2
8:50 做了一个假作法 小样例未过
8:55 开T3
8:58 写n<=20 的 dfs
9:10 写n<=2000 的 特判
9:25 思考特殊性质A
9:36 意外想出正解
9:45 证明完毕
10:30 调试T3 六个大样例全过
10:35 检查freopen
10:45 写完T2暴力
10:50 开T4 想出暴力&特性A
10:55 写T4 预估[272,296] ZJ 初一 1=
11:15 太无聊 遂乱打键盘 打得噼里啪啦 压力别人 
thanks for your reading
ZJ-J01514 RP++
希望上迷惑行为大赏
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
//freopen
*/ 
