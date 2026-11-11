#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long a[N],d;
long long dp[N];

bool check_g(int x){
	if(x>1&&a[x]-a[x-1]>d)	return false;
	if(x>2&&a[x]-a[x-2]<=d)	return false;
	if(x<n&&a[x+1]-a[x]>d)	return false;
	if(x<n-1&&a[x+2]-a[x]<=d)	return false;
	return true;
}bool check_b(int x){
	if(x!=1&&a[x-1]-a[x]>d)	return false;
	if(x!=n&&a[x+1]-a[x]>d)	return false;
	if(x<=2&&a[x]-a[x-2]>d)	return false;
	if(x>=n-1&&a[x+2]-a[x]>d)	return false;
	return true;
}

long long A[N];
#define get(x) lower_bound(A+1,A+1+n,x)-A
int lst[N],op[N],cnt[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)	cin>>a[i],A[i]=a[i];
		sort(A+1,A+1+n);
		
		for(int i=1,lst_=0,sum=0;i<=n;i++){
			if(check_g(i))	op[i]=1,lst[i]=lst_,cnt[i]=++sum;
			else if(check_b(i))	op[i]=2,lst_=i,sum=0;
			else	op[i]=lst_=sum=0;
		}
		long long ans=0;
//		for(int i=1;i<=n;i++){
//			if(op[i]==1){
//				if(op[i-1]==1)	dp[i]+=dp[i-1];
//				else if(lst[i])	dp[i]+=dp[lst[i]];
//				ans+=dp[i];
//			}else if(op[i]==2){
//				for(int j=get(a[i]-d);j<=i;j++)	dp[i]+=cnt[i]?cnt[i]:1;
//			}
//		}
		for(int i=3;i<=n;i++){
			if(op[i-1]==2&&op[i-2]==2)	dp[i]+=dp[i-1];
			else if(op[i-1]==1&&op[i]==1)	dp[i]+=dp[i-1];
			if(op[i-1]==2&&op[i]==2){
				for(int j=get(a[i]-d);j<=i;j++)	dp[i]+=cnt[j]?cnt[j]:1;
			}
		}
		for(int i=4;i<=n;i++){
			bool flag=true;
			for(int j=0;j<4;j++)
				if(op[i-j]!=2)	flag=false;
			if(flag)	ans++;
		}
		cout<<ans<<'\n';
		memset(dp,0,sizeof dp);
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5


2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/