#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	long long n,cnt=0;cin>>n;
	string s="";
	while(n--){
		long long a;char c;
		cin>>a>>c; 
		//for(long long i=0;i<a;i++)s+=c;
		while(a--)s+=c;
	}
	string s1="";
	for(long long i=s.size()-1;i>=0;i--)s1+=s[i];
	if(s==s1){
		cout<<cnt;
		return 0;
	}
	else{
		for(long long i=0;i<s.size()/2;i++){
			long long j=s.size()-1-i;
		//	cout<<cnt<<endl<<s<<endl;
			if(s[i]!=s[j]){
			s[j]=s[i];
			cnt++;
			}
			
			}
		}
		cout<<cnt;
	return 0;
}
