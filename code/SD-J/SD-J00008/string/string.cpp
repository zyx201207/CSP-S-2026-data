#include<bits/stdc++.h>
using namespace std;
long long minn=1e9+5;
long long x[200005];
char a[200005];
long long n;
string s="";
bool check(string s){
	long long len=s.size();
	for(long long i=0;i<len/2+1;i++){
		if(s[i]==s[len-1-i]) continue;
		else return 0; 
	}
	return 1;
}
long long cnt;
long long huiwen(string s){
	long long len=s.size();
	for(long long i=0;i<len/2;i++){
		if(s[i]==s[len-1-i]) continue;
		else cnt+=minn; 
	}
	return cnt;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>x[i];
		if(minn>x[i])minn=x[i];
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		x[i]-=minn;
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=x[i]+1;j++){
			s=s+a[i];
		}
	}
	if(check(s)){
		cout<<0;
		return 0;
	}
	cout<<huiwen(s);
	return 0;
}
