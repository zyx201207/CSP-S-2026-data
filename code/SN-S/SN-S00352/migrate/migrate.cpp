//刘泰豫 SN-S00352 西安市第一中学
#include<bits/stdc++.h>
using namespace std;
long long c,t,ans[2000005],num1[2000005];
void dfs(long long l,long long r,long long s,long long num){
	if(r<=1) return;
	if(num1[r]==num){
		ans[r]++;
	}num1[r]=min(num1[r],num);
	for(int i=1;i<=s;i++){
		dfs(l,r,i,num+1);
	}for(int i=r-1;i>=3;i--){
		dfs(l,i,s,num+1);
	}for(int i=l+1;i<r;i++){
		dfs(i,r,s,num+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<2000005;i++){
		num1[i]=2147583647;
	}for(int i=0;i<t;i++){
		long long n,d,x[2000005],ans1=0;
		cin>>n>>d;
		for(int j=0;j<n;j++){
			cin>>x[j];
		}dfs(0,n,d,0);
		for(int j=0;j<n;j++){
			if(ans[j]==2) ans1++;
			cout<<ans1<<endl;
		}
	}
	return 0;
}
