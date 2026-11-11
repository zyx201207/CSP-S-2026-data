/**
你我怎么两清
怎么忍心
怎么做回甲乙丙丁

难道非要耗尽
所有委屈
再赔上这一条烂命

爱情这场酷刑
叫人看清
爱与不爱之间的差距 
 
——《甲乙丙丁》 
**/ 
#include<bits/stdc++.h>
#define int long long
using namespace std;

int a[300500];
int pre[300500];

int Count1InBIN(int x){
	int ret=0;
	while(x){
		if(x%2) ret++;
		x/=2;
	}
	return ret;
}
bool cmp(int x,int y){
	int k1=Count1InBIN(x);
	int k2=Count1InBIN(y);
	if(k1==k2) return x>y;
	else return k1>k2;
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}
	pre[1]=a[1];
	for(int i=2;i<=m;i++){
		pre[i]=pre[i-1]&a[i];
	}
	cout<<pre[m];
	
	
	return 0;
}
