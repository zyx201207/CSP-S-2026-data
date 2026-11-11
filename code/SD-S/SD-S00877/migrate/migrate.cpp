#include<bits/stdc++.h>
using namespace std;
const int N=500;
#define li __int128
#define ull unsigned long long
li c,t,d;
li dp[N][N];
li n,x[N];
li cnt[N][N];
li ans;
li read(){
	string s,s1;
	cin>>s;
	if(s[0]=='-'){
		for(int i=1;i<s.size();i++){
			s1+=s[i];
		} 
	}else{
		s1=s;
	}
	//cout<<s1<<' ';
	li res=0;
	for(char cc:s1){
		res*=10;
		res+=(cc-'0');
	}
	if(s[0]=='-') res=-res;
	return res;
}
void prin(li a){
	string s;
	do{
		char cc=(a%10)+'0';
		a/=10;
		s+=cc;
	}while(a);
	cout<<s<<"\n";
	return;
} 
void solve(){
	memset(dp,0x3f,sizeof dp);
	memset(cnt,0,sizeof cnt);
	memset(x,0,sizeof x);
	ans=0;
	n=read();d=read();
	for(int i=1;i<=n;i++){
		x[i]=read();
		//prin(x[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]<=d){
				dp[i][j]=1;
				cnt[i][j]=1;
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dp[i][k]+dp[k][j]<dp[i][j]){
					dp[i][j]=dp[i][k]+dp[k][j];
					cnt[i][j]=1;
				}else if(dp[i][k]+dp[k][j]==dp[i][j]){
					//cout<<i<<' '<<j<<endl;
					cnt[i][j]++;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(cnt[i][j]==2&&dp[i][j]!=0x3f3f3f3f) ans++;
		}
	}
	prin(ans);
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	c=read();
	t=read();
	while(t--){
		solve();
	}
	return 0;
}
/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/
