#include<bits/stdc++.h>
using namespace std;
long long m,B=0,A=0;
long long a[500005];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n;
	cin>>n>>m;
	for(long long i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		if(a[i]==i) A++;
		if(i>2&&a[i]-a[i-1]==a[i-1]-a[i-2]) B++;
	}
	if(B==(n-2)) {
		for(long long i=1;; i++) {
			m-=i*(a[2]-a[1]);
			if(m==0) {
				cout<<i+1;
				break;
			} else if(m<0) {
				cout<<i;
				break;
			}
		}
		return 0;
	}
	if(A==n) {
		for(long long i=1;; i++) {
			m-=i;
			if(m==0) {
				cout<<i+1;
				break;
			} else if(m<0) {
				cout<<i;
				break;
			}
		}
		return 0;
	}
	long long ans=0;
	sort(a+1,a+n+1);
	for(long long i=n; i>=1; i--) {
		long long sum=m,w=0;
		for(long long j=i-1; j>=1; j--) {
			if(sum>=a[i]-a[j]) {
				sum-=(a[i]-a[j]);
				w++;
			} else {
				break;
			}
		}
		ans=max(ans,w+1);
	}
	cout<<ans;
	return 0;
}/*
嵊州市新城实验学校909 ZHY_LOVE_ZZQ
我洛谷号:yeweibo 

要AFO喽（虽然不情愿）
J 0+100+60+24
S 75+0+0+0
 
唉，后会无期。 

纵使日薄西山
此时此刻的光辉
盼君勿忘 

莫辞更坐弹一曲，为君翻作return 0；

希望中国OI越来越好
也祝CCF越来越好

 唯一的遗憾：OI生涯没有J一
 等我大学了再打！ 
*/ 
