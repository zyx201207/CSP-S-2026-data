#include<bits/stdc++.h>
using namespace std;
long long n,sum=0,tmp,ans=0,aa=0;
struct stu{
	long long num,idx;
	char c;
}; 
stu l[200005]={};
long long dp[200005]={};
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	l[0].idx=1;s+=' ';
	for(long long i=1;i<=n;i++){
		l[i].idx=l[i-1].idx+l[i-1].num;
		cin>>l[i].num>>l[i].c;
		aa+=l[i].num;
		for(long long j=0;j<l[i].num;j++){
			s+=l[i].c;
		}
		dp[i]=l[i].idx;
	}
	for(long long i=1;i<=aa/2;i++){
		if(s[i]!=s[aa-i+1]) ans++;
	}
//	sum=l[n].idx+l[n].num;
//	for(long long i=1;i<=(sum+1)/2;i++){
//		tmp=lower_bound(dp+(sum+1)/2,dp+n+1,sum-l[i].idx)-dp;
//		if(l[tmp].c!=l[i].c){
//			ans+=1;
//		}
//	}
//	for(long long i=1;l[i].idx+l[i].num<(sum+1)/2;i++){
//		tmp=lower_bound(dp+i+1,dp+n+1,sum-l[i].idx)-dp;
//		if(l[tmp].c!=l[i].c){
//			
//		}
//	}
	
	cout<<ans;
	return 0;
}
