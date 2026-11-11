#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,m,ans,dp[200010];
bool vis[200005],f1=true,f2=true;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//-------------------------------------
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1]*2+1) f1=false;
		if(a[i]!=i-1) f2=false;}
	if(f1){
		cout<<a[n-m+1];
		fclose(stdout);fclose(stdin);
		return 0;}
	if(f2){
		ans=a[n];
		for(int i=n-m+1;i<=n;i++) ans=ans&a[i];
		cout<<ans;
		fclose(stdout);fclose(stdin);
		return 0;}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		for(long long j=min(i,m);j>=1;j--){
			if(j==1) dp[j]=max(dp[j],a[i]);
			else dp[j]=max(dp[j],dp[j-1]&a[i]);}}
	cout<<dp[m];
	//-------------------------------------
	fclose(stdout);fclose(stdin);
	return 0;}