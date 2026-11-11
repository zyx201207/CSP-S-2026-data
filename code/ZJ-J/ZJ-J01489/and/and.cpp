#include<bits/stdc++.h>
using namespace std;
long long sum=0;
long long n,m;
string s[200010];
void check(long long t){
	if(t>=sum-1) return;
	long long c=0;
	long long k=sum;
	for(long long i=t+1;i<sum;i++){
		for(long long j=1;j<=n;j++){
			if(s[j][i]=='1') c++;
		}
		if(c>=m){
			k=i;
			break;
		} 
	}
	if(k==sum) return;
	long long num=0; 
	for(long long i=1;i<=n;i++){
		if(s[i][k]=='1'){
			s[++num]=s[i];
		}
	}
	n=c;
	check(k);
}
bool c(string x,string y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long Max;
	for(long long i=1;i<=n;i++){
		long long t;
		cin>>t;
		Max=max(Max,t);
		while(t){
			s[i]=char(t%2+'0')+s[i];
			t/=2;
		}
	}
	while(Max){
		Max/=2;
		sum++;
	}
	for(long long i=1;i<=n;i++){
		long long t=sum-s[i].size();
		for(long long j=1;j<=t;j++){
			s[i]='0'+s[i];
		}
	}
	check(-1);
	sort(s+1,s+1+n,c);
	long long ans=0;
	for(long long i=0;i<s[1].size();i++){
		ans=ans*2+s[1][i]-'0';
	}
	for(long long i=2;i<=m;i++){
		int t=0;
		for(long long j=0;j<s[i].size();j++){
			t=t*2+s[i][j]-'0';
		}
		ans=ans&t;
	}
	cout<<ans;
	return 0;
}
