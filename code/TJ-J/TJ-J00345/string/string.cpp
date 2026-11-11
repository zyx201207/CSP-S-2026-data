#include<bits/stdc++.h>
using namespace std;
int mi=1e9;
bool check(string s){
	int l=s.size();
	for(int i=1;i<=l/2-1;i++){
		if(s[i]!=s[l-1-i]) return false;
	}
	return true;
}
void dfs(string s,int cnt,int flag){
	int l=s.size();
	if(cnt==l && check(s)){
		mi=min(mi,flag+1);
		return ;
	}
	if(cnt==l && !check(s)) return ;
	char c=s[cnt];
	s[cnt]=s[l-1-cnt];
	dfs(s,cnt+1,flag+1);
	s[cnt]=c;
	dfs(s,cnt+1,flag);
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		for(int j=1;j<=x;j++){
			s+=y;
		}
	}
	if(check(s)){
		cout<<0;
		return 0;
	}
	dfs(s,0,0);
	cout<<mi;
	return 0;
} 
