#include<bits/stdc++.h>
using namespace std;
int a[100005];
int n,m;
int check(int x){
	int cnt=m;
	int ans=1;
	for(int i=x-1;i>=1;i++){
		int k=a[i+1]-a[i];
		cnt-=k;
		if(cnt<=0){
			return ans;
		}
		ans++;
	}
	return ans;
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	int maxx=0;
	for(int i=1;i<=n;i++){
		maxx=max(maxx,check(i));
	}
	cout<<maxx<<endl;
	/*
	枚举水晶能量值向哪个水晶靠拢
	9 8 4 2 1
	1 4 2 1 
	
	
	
	
	*/
	
	return 0;
}
