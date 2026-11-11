#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	//LL!
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		int l1=(s1[0]-'0')*10+s1[1]-'0';
		int l2=(s2[0]-'0')*10+s2[1]-'0';
		char ch1=s1[2],ch2=s2[2];
		if(l1==l2){
			if(max(ch1,ch2)<='C'||min(ch1,ch2)>='D'){
				if(ch1>ch2) swap(ch1,ch2);
				if(ch2-ch1==1||(ch2=='F'&&ch1=='D')){
					ans="1111";
				}
				else{
					ans="1110";
				}
			}
			else{
				ans="1100";
			}
		}
		else{
			ans="1000";
		}
	}
	else{
		ans="0000";
	}
	cout<<ans;
	return 0;
}
/*
初三，也许是第二次 AK CSP-J
做真题的时候实话说感觉压力大多了，但是也逼着自己多想了一把
实力非常有限，下午能稳定切掉像 J-T4 一样的下绿我就满意了，qwq
从初一摆 oi 搞 whk 到初二夏令营。初三开始梭哈 oi，自知水平落下两年，
zhzx 同级同学人均场紫，现在每次模拟赛接近垫底，
偶尔做了半场才切掉青题，结果被 20min 写加调秒掉。
巨佬学长 Feather_Moon，高一，已经能场切银牌题。
但是我从复健 oi 以来已经三个月了，进步竟然相当微小 /xk
csp-s 之后，还有一个月时间，希望学一点新东西，见识下各种 Trick，
然后做多技巧，长思考的题和代码量巨大的题
至少，在后面省选前能够突破瓶颈吧，一年竞赛，不能没有回报
还有原来的 cjer，希望你们数竞物竞 er 最后都能拿牌，还有 qsh，如果
csp-s 1=，他也能成为 cxzx 学长了 /x
The end. 从 10:10 分憋到 11:40，写了点唐诗东西。祝我活过下午不被打去世吧

等一下，我真的 ak 了吗
*/