#include<bits/stdc++.h>
using namespace std;
long long n; 
long long a;
string b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	cin>>n;
	while(n--){
		cin>>a>>b;
		for(long long i=1;i<=a;i++){
			s+=b;
		}
	}
	string m=s;
	reverse(m.begin(),m.end());
	if(s==m){
		cout<<0;
		return 0;
	}
	double l=s.size(); 
	long long cnt=0;
	for(int i=0;i<round(l/2.0);i++){
		if(m[i]!=s[i]){
			m[i]=s[i];
			cnt++;
		}
	}
	cout<<cnt;
	
	
	
	return 0;
}
