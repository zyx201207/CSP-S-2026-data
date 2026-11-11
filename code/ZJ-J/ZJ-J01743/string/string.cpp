#include<bits/stdc++.h>
using namespace std;
int n,ans;
string s;
char c;
inline int read(){
	int num=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		num=num*10+c-'0';
		c=getchar();
	}
	return num*f;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1,x;i<=n;i++){
		cin>>x>>c;
		for(int j=1;j<=x;j++) s+=c;
	}
	for(int i=ceil(s.size()/2);i<s.size();i++){
		if(s[i]!=s[s.size()-i-1]) ans++;
	}
	cout<<ans<<endl;
}
