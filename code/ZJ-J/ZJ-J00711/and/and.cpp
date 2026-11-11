#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int read(){
	int w=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*w;
}
int n,m;
int a[N],dp[N][5];
int ans;
int cand(int x,int y){
	return (x&y);
}
int main(){
	freopen("and.in","r",stdin);//freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		a[i] = read();
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i<=m){
				if(j==1){
					dp[j][1]=max(a[i],dp[j][0]);		
				}else{
					if(j<=i){
						dp[j][1] = max(cand(dp[j-1][0],a[i]),dp[j][0]);
					}
				}
			}else{
				if(j!=1){
					dp[j][1] = max(cand(dp[j-1][0],a[i]),dp[j][0]);
				}
				if(j==1){
					dp[j][1]=max(a[i],dp[j][0]);		
				}
			}
		}
		for(int k=1;k<=m;k++){
			dp[k][0] = max(dp[k][0],dp[k][1]);
		}
	}
	cout<<dp[m][0];
	return 0;
}
