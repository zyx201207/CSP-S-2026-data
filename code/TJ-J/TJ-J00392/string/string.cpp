#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int k;
char c;
long long l;
int check(string a,string b){
	int ans=0;
	for(long long i=0;i<a.size();i++){
		if(a[i]!=b[i]) ans++;
	}
	return ans;
}
bool check_hui(string s){
	for(long long i=0;i<=l/2;i++){
		if(s[i]!=s[l-i+1]) return 0;
	}
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>k;
		cin>>c;
		for(int i=1;i<=k;i++){
			s+=c;
		}
	}
	l=s.size();
	if(check_hui(s)) return cout<<0,0;
	if(l%2==0){
		string a="",b="";
		a=s.substr(0,l/2);
		b=s.substr(l/2); 
		reverse(b.begin(),b.end());
		cout<<check(a,b);
	}
	else{
		string a="",b="";
		a=s.substr(0,l/2);
		b=s.substr(l/2+1);
		reverse(b.begin(),b.end());
		cout<<check(a,b);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
 
