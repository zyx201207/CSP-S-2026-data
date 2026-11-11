#include<bits/stdc++.h>
using namespace std;
string s="",p="";
char c[100005];
int a[100005],n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	for(int i=s.size()-1;i>=0;i--){
		p+=s[i];
	}
	if(p==s){
		cout<<0;
	}
	else{
		cout<<s.size()/2;
	}
	return 0;
}
