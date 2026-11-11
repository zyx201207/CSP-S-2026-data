#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=2e5+8;
string aa(string s7){
	string s8="";
	for(int i=s7.size()-1;i>=0;i--){
		s8+=s7[i];
	}return s8;
}
ll dfs(int i,string s2,int w){
	if(i==s2.size()){
		string s4=s2;
		s4=aa(s4);
		if(s4==s2){
			return w;
		}return N;
	}
	ll cnt=dfs(i+1,s2,w);
	for(int j=0;j<26;j++){
		string s9=s2;
		s9[i]=char(j+'a'); 
		cnt=min(cnt,dfs(i+1,s9,w+1));
	}return cnt;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		ll x;
		cin>>x;
		string s1;
		cin>>s1;
		while(x--){
			s+=s1;	
		}
	}if(s.size()>N){
		cout<<"3000000000";
	}
	cout<<dfs(0,s,0);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
