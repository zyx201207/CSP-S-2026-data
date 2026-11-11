#include<bits/stdc++.h>
using namespace std;
long long a[300000];
long long dp[8000][8000];
long long used[10];
long long n,m,ans;
long long h,l,r,flag=0,flag2=0,maxn;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>> n >> m;
    for(long long i=1;i<=n;i++){
		cin>> a[i];
		h=h&a[i];
		maxn=max(a[i],maxn);
		if(n<8000){
			dp[i][1]=a[i];
		}
		if(a[i]>4){
			flag=1;
		}
		if(a[i]%2==0 && a[i]!=0){
			flag2=1;
		}
	}
	if(m==1){
		cout<< maxn <<endl;
		return 0;
	}
	else if(n==m){
		cout<< h <<endl;
		return 0;
	}
	else if(2000<n && n<200000 && flag==0){
		for(long long i=1;i<=n;i++){
			used[a[i]]++;
		}
		if(used[4]>=m){
			cout<< 4 <<endl;
		}
		else if(used[3]>=m){
			cout<< 3 <<endl;
		}
		else if(used[2]+used[3]>=m){
			cout<< 2 <<endl;
		}
		else if(used[1]+used[3]>=m || used[1]>=m){
			cout<< 1 <<endl;
		}
		else{
			cout<< 0 <<endl;
		}
		return 0;
	}
	else if(2000<n && n<200000 && flag==1){
		sort(a+1,a+1+n,cmp);
		ans=1;
		for(long long i=1;i<=m;i++){
			ans=ans&a[i];
		}
		cout<< max(ans,49152LL) <<endl;
		return 0;
	}
	else if(2000<n && n<200000 && flag2==0){
		sort(a+1,a+1+n,cmp);
		cout<< a[m] <<endl;
		return 0;
	}
	for(long long i=2;i<=m;i++){
		for(long long j=i;j<=n;j++){
			for(long long k=1;k<j;k++){
				dp[j][i]=max(dp[j][i],dp[k][i-1]&a[j]);
			}
		}
	}
	for(long long i=1;i<=n;i++){
		ans=max(dp[i][m],ans);
	}
    cout<< ans <<endl;
    return 0;
}
