#include<bits/stdc++.h>
using namespace std;
string a;
long long ans=INT_MAX;
bool pd(string s){
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i]){
			return false;
		}
	}
	return true;
}
void cl(string s,long long n,long long sum){
	if(sum>=ans||n>=a.size()-1){
		return;
	}
	if(pd(s)){
		ans=min(sum,ans);
	}
//	cout<<s<<endl;
	if(s[n]!=s[s.size()-n-1]){
		s[n]=s[s.size()-n-1];
		cl(s,n+1,sum+1);
	}else{
		cl(s,n+1,sum);
	} 
	return;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long l;
		char s;
		cin>>l>>s;
		for(int i=1;i<=l;i++){
			a+=s;
		}
	}
	cl(a,0,0);
	cout<<ans;
	return 0;
}