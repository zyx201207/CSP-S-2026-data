#include<bits/stdc++.h>
using namespace std;
//余俊辰 sn-s00626 西安市曲江第一学校 
const int N=5e5+10;
long long n,m,a[N],b[N];
int check(int cost){
	long long sum=0;
	for(int i=1;i<=n;i++)sum+=a[i];
	sum+=cost;
	long long sum1=sum,num=n;
	long long ad=sum/n;
	long long percost=0;
	for(int i=1;i<=n;i++)percost+=a[n]-a[0];
	if(cost>=percost)return n;
	for(int i=1;i<=n;i++){
		if(a[i]>ad)sum1=sum-a[i],num--;
	}
	ad=sum1/num;
	if(num==n && num*ad<=sum)num--;
	return num;
	
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=a[i];
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)a[i]-=a[1];
	long long ans=0;
	long long num=0;
	if(n<=50000){
		for(long long i=1;i<=m;i++){//花费 
			if(check(ans+i)>num)ans+=i,num=check(ans+i);
		}
		cout<<check(ans);
		return 0;
	}
	for(long long i=1<<50;i;i>>=1){//花费 
		if(check(ans+i)>num && ans+i<=m)ans+=i,num=check(ans+i);
	}
	cout<<check(ans);
	return 0;
}

