#include<bits/stdc++.h>
#define qwq return 0;
#define int long long
using namespace std;
int n,a[100005],sum=1,m;
/*
5 5
1 2 4 8 9
*/

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int ok=1;
	for(int i=1;i<n-1;i++) if(a[i+1]-a[i]!=a[i+2]-a[i+1]) ok=0;
	if(ok){
		int x=n-1,y=a[n],ans=0,num=1;
		while(1)
			if(ans+y-a[x]<=m) num++,ans+=y-a[x--];
			else break;
		cout<<num;
		qwq
	}
	for(int i=2;i<=n;i++){
		int cnt=0,num=1,x=i-1;
		while(x>0){
			if(cnt+a[i]-a[x]<=m) num++,cnt+=a[i]-a[x],--x;
			else break;
		}
		sum=max(sum,num);
	}
	cout<<sum;
	qwq
}
//Oct31==Dec25?

//15:12
//暴力
//O(n*n)
//45%pts

//15:46 
//暴力+优化+特判等差数列 
//O(n*n) 或 O(n) 
//预计75%pts 

//RP++
