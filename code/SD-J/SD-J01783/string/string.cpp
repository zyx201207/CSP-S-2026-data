#include<iostream>
using namespace std;
string s,s1,x;
long long l=0,n,a;
long long cnt=0,ans=0;
bool hw(string s){
	for(int i=0;i<s.size();i++){
		if(s[i]!=s[s.size()-i]){
			return false;
		}
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a>>x;
		for(int j=l;j<l+a;j++){
			s[j]=x[0];
		}
		l+=a;
	}
	if(hw(s)){
		cout<<0;
		return 0;
	}
	for(int i=0;i<l;i++){
		s1[i]=s[i];
	}
	for(int i=0;i<l;i++){
		if(s[i]!=s[l-i]){
			cnt++;
			s[i]=s[l-i];
		}
		if(s1[i]!=s1[l-i]){
			ans++;
			s1[l-i]=s1[i];
		}
	}
	ans=min(cnt,ans);
	cout<<ans;
	return 0;
}
