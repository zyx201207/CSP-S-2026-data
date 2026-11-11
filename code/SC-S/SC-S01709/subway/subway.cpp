#include <bits/stdc++.h>
freopen("subway.in",r,stdin);
freopen("subway.out",w,stdout);
using namespace std;
int c,n,m,d,q;
int w[500060],k[510],a[510][500060],t[510][500060];
int x[100010],y[100010];
bool dp[510][500060];
long long sum;
int main(){
	
	cin>>c>>n>>m>>d>>q;
	
		
	for(int i=1;i<=m;i++)cin>>w[i];
	cin>>k[1];
	for(int i=1;i<=k[1];i++){
	cin>>a[1][i]>>t[1][i];
	dp[1][a[1][i]]=true;
	}
	cin>>k[2];
	for(int i=1;i<=k[2];i++){
	cin>>a[2][i]>>t[2][i];
	dp[2][a[1][i]]=true;}
	for(int i=1;i<=q;i++){
	cin>>x[i]>>y[i];}
	
	while(q--){
	sum=w[x[i]]+w[y[i]];
	for(int i=1;i<=q;i++){
		
	
	}
}
	
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}