#include<bits/stdc++.h> 
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],f[N];
void sub1(){
	sort(a+1,a+n+1);
	int ans=0,s1=0;
	for(int i=1;i<=n;i++){
		f[i-1]=a[i]-a[i-1];
		ans+=a[i];
		if(a[i]<0) s1+=a[i];
	}
	int cnt=0;
	int i=0;
	while(cnt<=m&&i<=n){
		if(cnt+i*f[i]<=m){
			cnt+=i*f[i];
			i++;
		}else{
			break;
		}
	}
	cout<<min(i,n);
}
void sub2(){
	int cnt=0;
	int i=0;
	while(cnt<=m&&i<=n){
		if(cnt+i*f[i]<=m){
			cnt+=i*f[i];
			i++;
		}else{
			break;
		}
	}
	cout<<min(i,n);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int bj1=1,bj2=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) bj1=0; 
	}
	if(bj1==1){
		sub1();
		return 0;
	}
	sort(a+1,a+n+1);
	int ans=0,s1=0;
	for(int i=1;i<=n;i++){
		f[i-1]=a[i]-a[i-1];
		if(i>=2&&f[i-1]!=f[i-2]){
			bj2=0;
		}
		ans+=a[i];
		if(a[i]<0) s1+=a[i];
	}
	if(bj2==1){
		sub2();
		return 0;
	}
	int cnt=0;
	int i=0;
	while(cnt<=m&&i<=n){
		if(cnt+i*f[i]<=m){
			cnt+=i*f[i];
			i++;
		}else{
			break;
		}
	}
	int j=1;
	while(a[i]-a[j]>=(i-j)*f[i]){//减去最后面一个看是不是比前面那个大 
		cnt=cnt+(a[i]-a[j]);
		j++;
		while(cnt<=m&&i<=n){
			if(cnt+(i-j)*f[i]<=m){
				cnt+=(i-j)*f[i];
				i++;
			}else{
				break;
			}
		}
	}
	cout<<i-j+1;
	
	
	return 0;
}
////?????? 4 x 
/*
假装我能拿45
[0,75]
等等等总分连100分都没有我玩啥啊 
119

距离考试结束还有不到4分钟 
今年就初三了
要是不行都话估计就要短暂afo了
好难受啊比赛前几天不予许我请假训练啥意思啊
好崩溃啊班主任你干嘛
我又不能裸文化上七中还不让我走oi几个意思啊
难受啊兄弟
其实说是短暂afo但是确实不太清楚高中会不会真的就捡不起来了
哎难受啊
要提交了
晚安
世界毁灭vvv
求保佑
求119 1=（做梦 
*/ 