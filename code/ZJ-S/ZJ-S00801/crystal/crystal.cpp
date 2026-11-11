#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mx=5e5+5;
ll n,m,a[mx],sm[mx],ans=1;
int main(){
	//75pts
	//什么什么竟然这么多，一定不要挂啊（哭） 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++) sm[i]=sm[i-1]+a[i];
	//以上ok 
	if(n<=5000){
		//45pts
		//测试点1~9
		//如果我这个思路是正确的话就有45pts了（希望吧 
		for(ll i=1;i<=n;i++){
			for(ll j=i;j<=n;j++){
				ll t=(j-i+1)*a[j]-(sm[j]-sm[i-1]);
				if(t<=m) ans=max(ans,j-i+1);
			}
		}
		cout<<ans;
		//w这是正确的ba 
	}
//	else if(!f){
//		//15pts 
//		//测试点10~12 
//		for(int i=1;i<=100;i++){
//			ll xgcs=0,cnt=0;
//			for(int j=1;j<=n;j++){
//				if(xgcs<=m) ans=max(ans,cnt);
//				if(a[j]<=i) xgcs+=i-a[j],cnt++;
////				else break;
//			}
////			if(xgcs<=m) ans=max(ans,cnt);
////			else break;
////			cout<<"!"<<i<<" : "<<xgcs<<"qwq"<<cnt<<"\n"; 
//		}
//		cout<<ans;
//		//emmm其实还能做到更优但是好像没这个必要了 
//	}
	else{
		//30pts
		//测试点13~18 
		for(ll i=1;i<=n;i++){
			ll t=i*a[i]-sm[i];
			if(t<=m) ans=max(ans,i);
		}
		cout<<ans;
		//不不不这无疑是错误的 
		//诶但这个好像对于A和B的特殊性质是对的耶？ 
		//嗯因为都是等差的所以从哪里开始无关紧要so直接从开头开始就可以了 
		//嗯~我喜欢这个复杂度~ 
	} 
	return 0;
}
/* 
开ll了，已取消freopen的注释 
考虑部分分，区间dp?诶不对吧 
枚举每一个元素，使ta前面的元素都与ta相同，符合情况的，比较大小得出答案 
前缀和优化一下，这个元素之前要修改的次数就是i*a[i]-sm[i]了 
统计的不对啊，是i吧 
呃呃好像要两重枚举长度和开头再计算啊不算的话第四个大样例就过不了了 
算了，不会TLE的数据我写个正确的暴力，时间复杂度高的我就写这个错误的吧 
呃呃第四个大样例还是太大了啊 
蒜了，就这样吧，45pts很多了 
保佑保佑不要WA掉啊 
严肃开ll 
15:18结部分分一会再想 
15:32又想到的两个部分分结 
15:34又想到一个部分分遂尝试 
枚举1~100，这个是每个数要达到的值，统计个数然后用说不清楚的神秘方法算出值 
15:50检查完部分分打算直接保存进文件夹然后逼自己去看T2 
15:51不！！！测完第四个大样例发现是错的！疯了疯了 
16:00发现15pts部分分中代码的漏洞并且无法以相同的复杂度改正遂放弃 
啧被freopen吓死了差点写错了 
*/ 
