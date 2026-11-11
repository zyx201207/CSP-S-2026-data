//10:18 开题，来多骗点分
//		这题怎么这么长，没有 T3 精简 
//10:19 这什么奇妙的数据结构题 
//		暴力这是有 24pts 吗
//		打打看 
//10:44 什么题的暴力能让我打 30min 还只得 24pts 
//		那么就是我现在的总分是 [235,245]pts 
//		很明显不够 1= 
//10:57 不知道 #13,14 能否拿到，则本题为 [24,32]pts
//		总分是 [235,253]pts
//		不是怎么这么少，回去肝 T2 
//11:03 样例 4 怎么对了
//		那个总司令不会是 A 性质吧 
//		那么就是 [235,269]pts 
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int ans[300005];
bool vis[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=500&&m<=200){//task 1-6 24pts
		for(int i=1;i<=n;i++){
			vector<int>p;
			int l=p.size();
			for(int j=i;j<=n;j++){
				int k=0;
				bool flag=false;
				for(;k<l;k++){
					if(p[k]==a[j]){
						flag=true;
						break;
					}
				}
				if(flag){
					int pcnt=l-k;
					while(pcnt--)
						p.pop_back();
				}
				p.push_back(a[j]);
				l=p.size();
			}
			for(int j:p){
	//			cerr<<j<<' ';
				ans[j]++;
			}
	//		cerr<<'\n';
		}
	//	cerr<<'\n';
		for(int i=1;i<=m;i++)cout<<ans[i]<<((i==m)?'\0':' ');
		return 0;
	}
	if(m<=2){//[task 13,14 8pts]
		if(m==1){
			cout<<n;
			return 0;
		}
		int l1=-1,l2=-1;
		for(int i=n;i>=1;i--){
			if(a[i]==1){
				l1=i;
				break; 
			}
		}
		for(int i=n;i>=1;i--){
			if(a[i]==2){
				l2=i;
				break;
			}
		}
		cout<<l1<<' '<<l2;
		return 0;
	}
	//不可以，总司令！or [task 7-9,20 16pts]
	for(int i=n;i>=1;i--){
		if(!vis[a[i]]){
			vis[a[i]]=true;
			ans[a[i]]=i;
		}
	} 
	for(int i=1;i<=m;i++)cout<<ans[i]<<((i==m)?'\0':' ');
	return 0;
} 
/*
task 13,14
3 2
1 2 1

3 2
*/
//本题分数 [24,48]pts
//总分 [235,269]pts
//我的 1= 啊！ 
