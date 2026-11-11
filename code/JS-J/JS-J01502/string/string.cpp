#include<bits/stdc++.h>
using namespace std;
const int N=2010;
int dp[N][N];
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string s;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		for(int j=1;j<=a[i];j++){
			s.push_back(c[i]);
		}
	}
	int ns=s.size();
	s="*"+s;
	for(int len=2;len<=ns;len++){
		for(int i=1;i<=ns-len+1;i++){
			int j=i+len-1;
			int ii=i+1;
			int jj=j-1;
			if(s[i]==s[j]){
				dp[i][j]=dp[ii][jj];
			}else{
				dp[i][j]=dp[ii][jj]+1;
			}
		}
	}
	cout << dp[1][ns];
	return 0;
}
