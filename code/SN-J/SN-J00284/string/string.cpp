#include<bits/stdc++.h>
using namespace std;
long long  t,n,cnt;
char c;
struct node{
	char a;
	long long n;
}d[200010];
string s,x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>d[i].n>>d[i].a;
		s+=d[i].a;
	} 
	int b=0;
	for(int i=1;i<=s.size();i++){
		int l=s.size();
		if(s[i]!=s[l+1-i])b=1;
	}
	if(b!=1)cout<<0;
	else{
		for(int i=1;i<=s.size()/2;i++){
			int l=1;
			if(s[i]==d[1].a)cnt+=d[l].n;
			l++;
		}
		cout<<cnt;
	}
return 0;
}

