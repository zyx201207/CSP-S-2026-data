#include<bits/stdc++.h>
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Dor(i,x,y) for(int i=x;i>=y;i--)
#define ll long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],sum,ans,fb;
void dfs(int now,int cnt){
	if(cnt>m){
		ans=max(ans,sum);
		return ;
	}
	For(i,now,n){
		if(cnt==1){
			sum=a[i];
			dfs(i+1,cnt+1);
		}
		else{
			int x=sum;
			sum&=a[i];
			dfs(i+1,cnt+1);
			sum=x;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	For(i,1,n){
		cin>>a[i];
		if(a[i]!=i-1) fb=1;
	}
	if(n<=2000) dfs(1,1);
	else if(!fb){
		ans=n-1;
		Dor(i,n,n-m+1) ans&=a[i];
	}
	else{
		sort(a+1,a+n+1);
		ans=a[n-m+1];
	}
	cout<<ans;
	return 0;
}
/*
4 2
3 15 12 12

12

5 3
31 3 1 15 7

7

*/