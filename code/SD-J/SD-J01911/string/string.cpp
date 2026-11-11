#include<bits/stdc++.h>
using namespace std;
long long n,t;
char c;
string s,x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>t>>c;
		if(t>1000000000){
			for(long long j=1;j<=1000000;j++)x=x+c;
			for(long long j=1;j<=t/1000000;j++)s=s+x;
			for(long long j=1;j<=t%1000000;j++)s=s+c;
		}else if(t>1000000000){
			for(long long j=1;j<=100000;j++)x=x+c;
			for(long long j=1;j<=t/100000;j++)s=s+x;
			for(long long j=1;j<=t%100000;j++)s=s+c;
		}else if(t>10000000){
			for(long long j=1;j<=10000;j++)x=x+c;
			for(long long j=1;j<=t/10000;j++)s=s+x;
			for(long long j=1;j<=t%10000;j++)s=s+c;
		}else if(t>1000000){
			for(long long j=1;j<=1000;j++)x=x+c;
			for(long long j=1;j<=t/1000;j++)s=s+x;
			for(long long j=1;j<=t%1000;j++)s=s+c;
		}else if(t>100000){
			for(long long j=1;j<=100;j++)x=x+c;
			for(long long j=1;j<=t/100;j++)s=s+x;
			for(long long j=1;j<=t%100;j++)s=s+c;
		}else if(t>10000){
			for(long long j=1;j<=100;j++)x=x+c;
			for(long long j=1;j<=t/100;j++)s=s+x;
			for(long long j=1;j<=t%100;j++)s=s+c;
		}else if(t>1000){
			for(long long j=1;j<=10;j++)x=x+c;
			for(long long j=1;j<=t/10;j++)s=s+x;
			for(long long j=1;j<=t%10;j++)s=s+c;
		}else if(t>100){
			for(long long j=1;j<=100;j++)x=x+c;
			for(long long j=1;j<=t/10;j++)s=s+x;
			for(long long j=1;j<=t%10;j++)s=s+c;
		}else for(long long j=1;j<=t;j++)s=s+c;
	}long long i=0,j=s.size()-1,cnt=0;
	while(i<j){
		if(s[i]!=s[j])cnt++;
		i++,j--;
	}cout<<cnt;
	return 0;
}

