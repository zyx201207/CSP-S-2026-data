#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
bool a[N][35];
int b[N];
struct Node{
	int num;
	long long v;
}dp[N];
int n,m;
int k,mink=40;
long long qmi(long long num,int t){
	long long res=1;
	while(t){
		if(t&1) res*=num;
		num*=num;
		t>>=1;
	}return res;
}
long long cnt,ans;
bool cmp(Node a1,Node a2){
	return a1.v>a2.v;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		k=31;
		cin>>cnt;
		b[i]=cnt;
		while(cnt){
			a[i][k]=(cnt&1);
			cnt>>=1;
			k--;
		}mink=min(mink,k);
		dp[i].num=i;
		
	}mink++;
	for(int j=mink;j<=31;j++){
		cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i][j]==1) cnt++;
		}
		if(cnt<m) continue;
		for(int i=1;i<=n;i++){
			if(a[i][j]==1) dp[i].v+=qmi(2,31-j);
			
		}
	}sort(dp+1,dp+n+1,cmp);
	for(int i=1;i<=m;i++){ 
		if(i==1) ans=b[dp[i].num];
		else ans=ans & b[dp[i].num];
	}cout<<ans;
	return 0;
}
