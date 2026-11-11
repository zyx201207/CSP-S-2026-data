#include<bits/stdc++.h>
using namespace std;
long long n,ans,a[200005],l,r,cnt,aaa;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++) cin>>a[i]>>c[i];
	if(n==1||n==0){
		cout<<0;
		return 0;
	}
	bool f=1;
	for(long long i=1;i<n;i++)
		if(c[i+1]!=c[i])f=0;
	if(f==1){
		cout<<0;
		return 0;
	}f=1;
	for(long long i=1;i<n;i++){
		if(a[i]!=a[i+1]) f=0;
	}
	if(f==1){
		string s1,ss1;
		for(long long i=1;i<=n;i++)
			s1+=c[i];
		ss1=s1;
		reverse(s1.begin(),s1.end());
		if(s1==ss1){
			cout<<0; return 0;
		}
	}
	string s;
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	string s2=s;
	reverse(s.begin(),s.end());
	if(s2==s){
		cout<<0;
		return 0;
	}
	else{
		for(long long i=0;i<s.size();i++){
			if(s[i]!=s2[i]) cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
