#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
int a[200010];
int n,m;
int dfs(int c,int lst,int now){
	if(c==m){
		return now;
	}else{
		int maxx=INT_MIN;
		if(c==0){
			for(int i=lst+1;i<=n;i++){
				maxx=max(maxx,dfs(c+1,i,a[i]));
			}
		}else{
			for(int i=lst+1;i<=n;i++){
				maxx=max(maxx,dfs(c+1,i,now&a[i]));
			}
		}
		return maxx;
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	int ans=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		ans=ans&a[i];
	}
	if(n==m){
		cout<<ans;
		return 0;
	}
	if(m==1){
		int maxx=INT_MIN;
		for(int i=1;i<=n;i++){
			maxx=max(a[i],maxx);
		}
		cout<<maxx;
		return 0;
	}
	sort(a+1,a+n+1);
	if(n>=10000){
		int qqq=a[2];
		for(int i=3;i<=n;i++){
			qqq=qqq&a[i];
		}
		cout<<qqq;
		return 0;
	}
	int lst=INT_MIN; 
	cout<<dfs(0,1,0);
	return 0;
}
/*
4 2
3 15 12 12
*/


