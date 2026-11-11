#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int MAXN=5e5+10;
int n,m,a[MAXN],sum,ans;
int read(){
	int f=1,x=0;
	char ch;
	ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch-'0');
		ch=getchar();
	}
	return x*f;
} 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
//	cin>>n>>m;
	for(int i=1;i<=n;i++){
		a[i]=read();
//		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int head=1;
	for(int i=1;i<=n;i++){
		sum+=(i-head)*(a[i]-a[i-1]);
		while(sum>m){
			sum-=a[i]-a[head];
			head++;
		}
		ans=max(ans,i-head+1);
	}
	cout<<ans<<"\n";
	return 0;
} 
/*
5 5
1 2 4 8 9   
out:3

5 8 
-3 -1 2 2 7
out:4

crystal
*/
