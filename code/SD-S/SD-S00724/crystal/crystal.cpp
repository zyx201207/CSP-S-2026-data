#include<bits/stdc++.h>
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	io;
	long long n,m,Max=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long l=1,r=1;
	while(r<=n){
		while(a[r+1]==a[r]&&r+1<=n) r++;
		while(a[l]==a[l-1]&&l-1>=1) l--;
		long long s=m,ans=a[l];
		while(s){
			long long t1=0,t2=0;
			bool fi=true,se=true;
			if(l-1>=1) t1=a[l-1];
			else fi=false;
			if(r+1<=n) t2=a[r+1];
			else se=false;
			if(fi==false&&se==false){
				Max=n;
				break;
			}
			if(fi==true&&se==true){
				if(ans-t1<=(r-l+1)*(t2-ans)){
					if(ans-t1>s){
						Max=max(Max,r-l+1);
						break;
					}
					l--;
					s-=ans-a[l];
				}
				else if(ans-t1>(r-l+1)*(t2-ans)){
					if((r-l+1)*(t2-ans)>s){
						Max=max(Max,r-l+1);
						break;
					}
					r++;
					s-=(r-l)*(a[r]-ans);
					while(a[r+1]==a[r]&&r+1<=n) r++;
					ans=a[r];
				}
			}
			else if(fi==true){
				if(ans-t1>s){
					Max=max(Max,r-l+1);
					break;
				}
				l--;
				s-=ans-a[l];
			}
			else if(se==true){
				if((r-l+1)*(a[r+1]-ans)>s){
					Max=max(Max,r-l+1);
					break;
				}
				r++;
				s-=(r-l)*(a[r]-ans);
				ans=a[r];
			}
			while(ans==a[r+1]&&r+1<=n) r++;
			while(ans==a[l-1]&&l-1>=1) l--;
			Max=max(Max,r-l+1);
		}
		if(r+1>n) break;
		l=r+1;
		r=l;
	}
	cout<<Max;
	return 0;
}
/*
14:46 暴力！！！ 
15:07 eee暴力打错了想一想 
15:15 想了个正确一点的暴力（？写写看吧mn2logn 接近n3 
15:59 艰难过了小样例
16:01 不是这能过样例3,4也只差一点,有希望我直接死磕 
16:35 好像过了但不确定多少分,时间复杂度未知（？）差不多nm（？）打其他题的暴力了 
18:23 饿啊其他题一点都不会只能空城计了,60pts吧（万一59pts进noip呢）
5 5
1 2 4 8 9





*/
