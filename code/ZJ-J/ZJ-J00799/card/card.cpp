#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mxn=5e5+5;
const ll mxm=3e5+5; 
ll n,m,a[mxn],ans[mxm];
bool f;
ll ve[mxn];
int main(){
	//40pts
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) f=1;
	}
	if(f&&n<=5000){
		//24pts
		//测试点1~6
		//O(n)模拟每一轮，O(n)放牌，另外O(n)寻找现在已经放好的牌里面有没有现在这张
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++) ve[j]=0;
			ll now=0;
			ve[++now]=a[i];
			for(ll j=i+1;j<=n;j++){
				bool f=0;
				ll wz=0;
				for(ll k=1;k<=now;k++){
					if(ve[k]==a[j]){
						f=1;
						wz=k;
						break;
					}
				}
				if(f){
					for(ll i=wz;i<=now;){
						ve[i]=0;
						now--;
					}
				}
				ve[++now]=a[j];
			}
//			cout<<"now:"<<now<<"\n";
			bool vis[mxn]={0};
			for(ll i=1;i<=now;i++){
				if(!vis[ve[i]]) ans[ve[i]]++,vis[ve[i]]=1;
			}
		} 
		for(ll i=1;i<=m;i++) cout<<ans[i]<<" ";
		//两个小样例已过
		//大样例测不出来是否正确 
	}
	else if(!f){
		//16pts 
		//特殊性质A：测试点7~9，测试点20 
		//说明每次放牌时只有最右边的牌有可能会被拿走（一样），那么就从右往左找 
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++) ve[j]=0;
			ll now=0;
			ve[++now]=a[i];
			for(ll j=i+1;j<=n;j++){
				bool f=0;
				ll wz=0;
				for(ll k=now;k>=1;k--){
					if(ve[k]==a[j]){
						f=1;
						wz=k;
					}
					else break;
				}
				if(f){
					for(ll i=wz;i<=now;){
						ve[i]=0;
						now--;
					}
				}
				ve[++now]=a[j];
			}
//			cout<<"now:"<<now<<"\n";
			bool vis[mxn]={0};
			for(ll i=1;i<=now;i++){
				if(!vis[ve[i]]) ans[ve[i]]++,vis[ve[i]]=1;
			}
		} 
		for(ll i=1;i<=m;i++) cout<<ans[i]<<" ";
		//唯一能验证的大样例4过了 
	}
	return 0;
}
//开ll了，已去掉freopen的注释 
//10:34保存好T1T2准备继续写部分分 
//11:22结 
//11:30统一检查结束，再去看看T3正解能不能想出来吧 
