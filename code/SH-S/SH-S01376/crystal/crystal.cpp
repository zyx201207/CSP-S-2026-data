#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
int maxx=1;
int fnt=1;
int f[2];
int g=0;
signed main(){
	freopen("crystal.in","r",stdin);	
	freopen("crystal.out","w",stdout);
	int n,m;
	int d,b;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	d=m;
	sort(a+1,a+1+n,greater<int>());
	int cnt=1;
	int c=a[1];
	for(int i=2;i<=n;i++){
		m-=(c-a[i]);
		c=a[fnt];
		cnt++;
		if(m<0){
			while(cnt>=1&&m<0){
				cnt--;
				maxx=max(cnt,maxx);
				while(a[fnt]-a[fnt+1]==0){
					fnt++;
					cnt--;
				}
				m+=(a[fnt]-a[fnt+1])*cnt;
				fnt++;
			}
			if(m<0){
				fnt=i;
				maxx=max(cnt,maxx);
				cnt=1;
				m=d;
			}
		}
		maxx=max(cnt,maxx);
	}
	for(int i=n;i>=1;i--){
		if(a[n]==a[n-1]){
			maxx--;
			break;
		}
	}
	cout<<maxx+1;
	return 0;
} 
















//freopen("crystal.in","r",stdin);
//freopen
/*
图灵老师保佑
冯诺依曼老师保佑
高斯老师保佑
祖冲之老师保佑 
今天是阳明老师的生辰诶…………554岁生辰快乐awa 
以及今天是万圣节……万圣节给圣贤过生辰，这很合理awa
0v0
freopen
嗯对的cos一下张仪
我是洛谷@cutecat1，一个普通的史同女，杂食，欢迎来找我玩
想上迷惑行为大赏（CSP-S真的有这种东西吗）
给你们看个好东西： 
《念张师》（but张居正版） 
张居正老师～
我还记得你～
一句一句～
把我拉进改革里～

还有另一个东西：
雷霆荀门集体蹦迪
轮椅孙膑鬼火漂移
神秘张仪六国蹦迪
应侯范雎公路平移
合纵联军阴间来袭
这里没有抗秦人
又或者说抗秦的都不是人

18:24全部调试完成
T1:100-50
T2:0-10
T3:0-10
T4:0
总分:120-70 
*/
 
