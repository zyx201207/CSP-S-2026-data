#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N];
long long flag1=1,a1=0;
long long flag2=1,d=0;
long long s[N],cost[N];
int main(){
	//
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i>=1){
			a1=a[1];
			if(a[i]!=a1) flag1=0;
		}
		if(i>=2){
			d=a[2]-a[1];
			if(a[i]-a[i-1]!=d) flag2=0;
		}
	}
	//
	if(flag1==1){
		printf("%lld",n);
		return 0;
	}
	//
	if(flag2==1){
		long long ans=0;
		for(long long i=1;(i+1)*i/2<=(m/d);i++){
			ans=i;
		}
		printf("%lld",ans+1);
		return 0;
	}
	//
	sort(a+1,a+1+n);
	//
	if(n){
		long long ans=0;
		for(int i=1;i<=n;i++){
			long long m1=m,ans1=0;
			for(int j=i;j>=1;j--){
				if(m1>=a[i]-a[j]){
					m1-=a[i]-a[j];
					ans1++;
				}else{
					break;
				}
			}
			ans=max(ans1,ans);
		}
		printf("%lld",ans);
	}
	/*
	long long ans=0;
	cost[1][1]=0;
	for(int i=2;i<=n;i++){
		cost[i][1]=cost[i-1][1]+(i-1)*(a[i]-a[i-1]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cost[i][j]=cost[i][1]-cost[j-1][1]-(j-1)*(a[i]-a[j]);
		}
	}
	*/
	fclose(stdin);
	fclose(stdout);
	//
	return 0;
} 
/*
5 10
5 5 5 5 5

5
*/
/*
5 7
1 2 3 4 5

4
*/
/*
5 5
1 2 4 8 9

3
*/
/*
5 8
-3 -1 2 2 7

4
*/
