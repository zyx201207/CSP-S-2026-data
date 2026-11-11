//09:41 开题……多给我点分吧……我没切掉 T2……
//		这题似曾相识欸 
//		好吧暴力只有 25pts。先打上。 
//09:48 暴力打完了搞性质 
//09:56 咱们也是成功搞到 50pts，总分为 206pts
//		呃啊总分怎么这么少啊 
//10:14 凭借人类智慧骗到了 [5,15]pts，本题总分为 [55,65]pts，全局总分为 [211,221]pts
//		注意到 211pts 是我模拟赛成绩 
//10:17 咱们去看一眼 T4 吧 
//11:34 回来带着 [235,269]pts 尝试继续骗分
//11:42 貌似无法骗分了 
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int ans=0;
bool checkA(){
	for(int i=0;i<n;i++){
		if(__builtin_popcountll(a[i])!=__lg(a[i]+1))
			return false;
	}
	return true;
}
bool check1617(){
	for(int i=0;i<n;i++){
		if(a[i]>=4)
			return false;
	}
	return true;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	if(n<=20){//task 1-5 25pts
		for(int i=0;i<(1<<n);i++){
			int l=__builtin_popcountll(i);
			if(l!=m)continue;
			int res=0;
			bool flag=false;
			for(int j=0;j<n;j++){
				if(i&(1<<j)){
					if(!flag)
						flag=true,res=a[j];
					else
						res&=a[j];
				}
			}
			ans=max(ans,res);
		}
		cout<<ans;
		return 0;
	}
	if(m==1){//task 6 5pts
		for(int i=0;i<n;i++)ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}
	if(m==n){//task 7 5pts
		for(int i=0;i<n;i++){
			if(i==0)ans=a[i];
			else ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2){//task 8-10 15pts
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j)continue;
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(checkA()){//task 13 5pts
		sort(a,a+n);
		cout<<a[n-m];
		return 0;
	}
	if(check1617()){//[task 16,17 10pts]
		vector<int>cnt(4);
		for(int i=0;i<n;i++)cnt[a[i]]++;
		if(m<=cnt[3])cout<<3;
		else if(m<=cnt[3]+cnt[2])cout<<2;
		else if(m<=cnt[3]+cnt[1])cout<<1;
		else cout<<0;
	}
	return 0;
} 
//A 性质就是样例 2 
//本题分数 [55,65]pts
