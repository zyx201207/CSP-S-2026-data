#include<bits/stdc++.h>
using namespace std;
int n,a,num=0;
char c;
string s="",b="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s+=c;
		}
	}
	for(int i=s.size()-1;i>=0;i--){
		b+=s[i];
	}
	if(s==b){
		cout<<"0";
		return 0;
	}
	for(int i=0;i<s.size();i++){
		if(s[i]!=b[i]){
			num++;
			b[i]=s[i];
			s[s.size()-i-1]=s[i];
		}
		if(s==b){
			break;
		}
	}
	cout<<num;
	return 0;
}

