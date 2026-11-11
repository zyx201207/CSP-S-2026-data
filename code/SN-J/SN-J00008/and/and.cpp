#include<bits/stdc++.h>
using namespace std;
int n,m;
string l[200005];
string to_2(long long x){
	string s="";
	while(x>0){
		if(x%2==0) s+="0"; 
		else s+="1";
		x/=2;
	}
	return s;
}
int to_10(string s){
	long long ans=0;
	for(int i=0;i<s.size();i++){
		ans+=(s[i]-'0')*pow(2,i);
	} 
	return ans;
} 
string and2(string a,string b){
	string ans="";
	for(int i=0;i<min(a.size(),b.size());i++){
		if((a[i]-'0')&&(b[i]-'0')){
			ans+="1";
		}
		else{
			ans+="0";
		}
	}
	int num;
	if(a.size()>=b.size()){
		num=a.size()-b.size();
	}
	else{
		num=b.size()-a.size();
	}
	for(int i=1;i<=num;i++){
		ans+="0";
	}
	return ans;
}
int maxn=0;
void dfs(int n1,int step,string ans){
	if(step>m){
		maxn=max(maxn,to_10(ans));
		return;
	}
	if(n1>n) return;
	if(step==1){
		l2[step]=to_10(l[n]);
		dfs(n1+1,step+1,l[n]);
		l2[step]=0;
		dfs(n1+1,step,ans);
	}
	else{
		l2[step]=to_10(l[n]);
		dfs(n1+1,step+1,and2(ans,l[n]));
		l2[step]=0;
		dfs(n1+1,step,ans);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		long long x;
		cin>>x;
		l[i]=to_2(x);
	}
	dfs(1,1,"");
	cout<<maxn;
	return 0;
} 
