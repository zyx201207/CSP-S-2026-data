//By JuRuoOIer
//Problem:crystal
//Expected:100 (n log n)
//idea+impl:18min
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<iomanip>
#include<map>
#include<set>
#include<vector>
#include<cmath>
#include<cctype>
#include<random>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define LL __int128
#define lf double
#define ld long double
using namespace std;
void file(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
}
ll n,m,a[500010],pre[500010],ans;
int main(){
	file();
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		a[i]-=a[1];
	}
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
		ll l=0,r=i-1;
		while(l<r){
			ll mid=(l+r>>1);
			if((i-mid)*a[i]-(pre[i]-pre[mid])<=m){
				r=mid;
			}
			else{
				l=mid+1;
			}
		}
		ans=max(ans,i-r);
	}
	cout<<ans;
	return 0;
}

/*
暗涌 至喷涌 谁能懂少年汹涌
天黑黑越过囚笼 狂想曲挠破心胸
乌托邦美而无用 幻想国有恃无恐
屈居万人之上 左右撕裂之中
一步之遥 总会一步踩空 
*/
