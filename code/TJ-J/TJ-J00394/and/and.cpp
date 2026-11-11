#include<bits/stdc++.h>
using namespace std;
string overturn(string s){
	string ans="";
	for(int i=s.length()-1;i>=0;i++){
		ans+=s[i];
	}
	return ans;
}
string Copy(int a,char c){
	string ans="";
	for(int i=1;i<=a;i++){
		ans+=c;
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		s+=Copy(a,c);
	}
	string u=overturn(s);
	cout<<"s="<<s<<",u="<<u<<endl;
	int y=0;
	for(int i=0;i<s.length();i++){
		if(s[i]!=u[i]){
			y++;
		}
	}
	cout<<y/2;
	return 0;
} 
