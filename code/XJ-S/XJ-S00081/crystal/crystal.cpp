#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long int ll;

ll n,m,maxcnt,maxvalcnt;
ll arr[100005];
ll brr[100005]; 

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	 
	//初始化
	memset(arr,0,sizeof(arr));
	memset(brr,-1,sizeof(brr));
	
	//输入 
	cin>>n>>m;
	for(ll a=1;a<=n;a++){
		cin>>arr[a];
	}
	
	//特判 
	if(n==1)
		cout<<1;
	
	sort(arr+1,arr+n+1);
	maxcnt=0;
	maxvalcnt=0;
	for(ll a=1;a<=n;a++){
		for(ll b=1;b<=a;b++){
			brr[b]=arr[a]-arr[b];
		}
		
		ll valcnt=0,cnt=0;
		for(ll b=1;b<=n;b++){
			if(valcnt>m)
				break;
			if(brr[b]!=-1)
				valcnt+=brr[b];
		}
		if(valcnt>=maxvalcnt&&valcnt<=m){//找到最大水晶 
			for(ll b=1;b<=n;b++){
				if(brr[b]!=-1)
					cnt++;
				}
			maxcnt=max(cnt,maxcnt);
		}
		memset(brr,-1,sizeof(brr));
	}
	cout<<maxcnt;
	return 0;
}
