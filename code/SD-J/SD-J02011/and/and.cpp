#include<iostream>
#define endl '\n'
using namespace std;
int a[200005];
int po(int n){
	int ans=1;
	if(n==0)return ans;
	for(int i=1;i<=n;i++)ans*=2;
	return ans;
}
string tentwo(int n){
	string ans="",ans1="";
	while(n>0){
		ans+=((n%2)+'0');
		n/=2;
	}
	for(int i=ans.size()-1;i>=0;i--)ans1+=ans[i];
	return ans1;
}
int twoten(string s1){
	int ans=0;
	string s="";
	for(int i=s1.size()-1;i>=0;i--)s+=s1[i];
	for(int i=0;i<s.size();i++)ans+=(s[i]-'0')*po(i);
	return ans;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,maxn=-1e9;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	cout<<a[n];
	return 0;
 } 
