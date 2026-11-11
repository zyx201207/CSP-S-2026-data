#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
 struct emp{
	int a,b;
}s[N];
int dp[5005][5005];
bool cmp(emp x,emp y){
	if(x.a!=y.a) return x.a<y.a;
}
signed main(){
	 freopen("crystal.in","r",stdin);
 	freopen("crystal.out","w",stdout);
 	ios::sync_with_stdio(false);
 	cin.tie(0);
 	int n,m;
	 cin>>n>>m;
	int cha;
	bool M=1,G=1;
	cin>>cha;
	for(int i=1;i<=n;i++){
		cin>>s[i].a;
		if(i==1){
			cha=s[i+1].a-s[i].a;
		if(s[i+1].a-s[i].a!=cha){
		
			G=0;}
		}
		if(s[i].a!=i)
			M=0;
	}
	s[1].b=0;
	if(M){
		if(m>n&&n==2){
			cout<<2;
			return 0;
		}
		int cnt=1;
		for(int i=2;i<=n;i++){
			if(m-i>=0){
			
			m-=i;
			cnt++;}
			else break;
		}
		cout<<cnt; 
		return 0;
	}
	else if(G){
		int cnt=0;
		while(m){
			m-=cha;
			cnt++;
			
		}
	cout<<cnt;
	return 0;
	}
	sort(s+1,s+1+n,cmp);
	 int maxn=0,maxx=0;
	 for(int i=1;i<=n;i++){
	 	for(int j=1;j<=n;j++){
	 		  maxx=dp[i][j];
		 }
	 }
	 for(int j=1;j<=n;j++){
	 	for(int i=0;i<=n;i++){
		 if(dp[i][j]>=maxn&&dp[i][j]<=j-i>maxx){
	 			maxn=dp[i][j];
			 maxx=j-i+1;
		 }
	 	}	
	 }
	
	 cout<<maxx;
	 return 0;
 }
